/*	$Csoft$	*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <glib.h>
#include <SDL.h>

#include <engine/debug.h>
#include <engine/event.h>
#include <engine/view.h>
#include <engine/object.h>
#include <engine/world.h>
#include <engine/char.h>
#include <engine/map.h>

struct world *
world_create(char *name)
{
	world = (struct world *)malloc(sizeof(struct world));
	if (world == NULL) {
		perror("world");
		return (NULL);
	}

	/* Initialize the world structure. */
	object_create(&world->obj, name, NULL, DESTROY_HOOK);
	world->obj.destroy_hook = world_destroy;
	
	world->objs = NULL;
	world->chars = NULL;
	world->maps = NULL;
	world->nobjs = 0;
	world->nchars = 0;
	world->nmaps = 0;
	world->agef = 0.01;
	pthread_mutex_init(&world->lock, NULL);

	return (world);
}

void
world_destroy(struct object *obj)
{
	struct world *wo = (struct world *) obj;
	GSList *woc = NULL;

	/*
	 * Destroy all objects. Destroy handlers might happen
	 * to modify the object list, so we make a copy of it.
	 */
	if (pthread_mutex_lock(&wo->lock) == 0) {
		woc = g_slist_copy(wo->objs);
		pthread_mutex_unlock(&wo->lock);
	} else {
		perror("world");
	}

	/* Destroy all registered objects. */
	g_slist_foreach(woc, (GFunc)object_destroy, NULL);

	/* Perform deferred garbage collection (ie. for maps). */
	object_lategc();
	
	pthread_mutex_destroy(&wo->lock);
}

#ifdef DEBUG

void
world_dump(struct world *wo)
{
	printf("[%d objs]\n", wo->nobjs);
	g_slist_foreach(wo->objs, (GFunc)object_dump_obj, NULL);
	printf("\n");
	
	printf("[%d maps]\n", wo->nmaps);
	g_slist_foreach(wo->maps, (GFunc)map_dump_map, NULL);
	printf("\n");

	printf("[%d characters]\n", wo->nchars);
	g_slist_foreach(wo->chars, (GFunc)char_dump_char, NULL);
	printf("\n");
}

#endif /* DEBUG */

