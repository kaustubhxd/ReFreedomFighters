"""specs_s427.py - unclaimed-42 batch 7 (claim 7): CCivilianPathList::Load (0x5bedd0), thiscall, one stack argument (ret 4).
The ZLoadGame object is a logging vtable whose dword and pointer-sized reads (slots +0x48, +0x40) write the next value of a
list fixed in the gen, so the original and the port consume the same values in the same order. Slot +0x18 (block read)
logs. The element loader 0x5beeb0 is original code on the element block. The engine object at 0x70039c answers slot +0x58."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _load(c):
    self_ = zero_obj(c, 0x1000)
    n = c.rng.randrange(0, 3)
    n2 = c.rng.randrange(0, 4)
    vals = [n, n2] + [c.rng.randrange(0, 40) for _ in range(64)]
    it = iter(vals)

    def read_out(e, a):
        e.w32(a[0], next(it, 0))
        return (None, None)

    ld = logged_obj(c, 'ZLoadGame', 0x80, impl={0x48: read_out, 0x40: read_out},
                    argwords={0x48: 1, 0x18: 2, 0x40: 1})
    en = logged_obj(c, 'ZEngineLoadObj', 0x80, impl={0x58: lambda e, a: (zero_obj(c, 0x100), None)}, argwords={0x58: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [self_, ld]


S(0x5bedd0, 'CCivilianPathList::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-42 batch 7; ZLoadGame reads from a fixed list; element loader 0x5beeb0 original')
