with interfaces.c.strings;

package body agar.gui.colors is
  package cs renames interfaces.c.strings;

  use type c.int;

  function load (path : cs.chars_ptr) return c.int;
  pragma import (c, load, "AG_ColorsLoad");

  function save (path : cs.chars_ptr) return c.int;
  pragma import (c, save, "AG_ColorsSave");

  function save_default return c.int;
  pragma import (c, save_default, "AG_ColorsSaveDefault");

  function load (path : string) return boolean is
    ca_path : aliased c.char_array := c.to_c (path);
  begin
    return load (cs.to_chars_ptr (ca_path'unchecked_access)) = 0;
  end load;

  function save (path : string) return boolean is
    ca_path : aliased c.char_array := c.to_c (path);
  begin
    return save (cs.to_chars_ptr (ca_path'unchecked_access)) = 0;
  end save;

  function save_default return boolean is
  begin
    return save_default = 0;
  end save_default;

end agar.gui.colors;
