/*	$Csoft: engine.h,v 1.1 2002/01/30 12:30:04 vedge Exp $	*/

#include <libfobj/fobj.h>

#include <engine/debug.h>
#include <engine/view.h>
#include <engine/object.h>
#include <engine/xcf.h>
#include <engine/world.h>
#include <engine/map.h>
#include <engine/event.h>
#include <engine/char.h>

#define ENGINE_VERSION	"0.1"

struct gameinfo {
	char	*prog;
	char	*name;
	char	*copyright;
	int	 ver[2];
};

int	engine_init(int, char **, struct gameinfo *);
int	engine_mapedit(void);
void	engine_destroy(void);
void	engine_join(void);

