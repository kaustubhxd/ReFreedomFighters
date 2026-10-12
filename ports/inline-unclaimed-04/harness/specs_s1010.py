"""specs_s1010.py - unclaimed-04 batch 10 (docs/20-unclaimed-04.md): ZVehicleIf::~ZVehicleIf (0x51aa70, dtor).
thiscall, one stack argument (flags, ret 4). The destructor stores the class vtable (0x69f364), calls the base
destructor 0x519430 (original code), and when flag bit 0 is set frees the object with 0x634273 (cdecl, pointer and size
0x1c). It returns this. The free is a Python hook that logs its arguments (GUESS: the usual CRT delete with size)."""
from pilot import S


def _setup(c):
    def free34(em, r):
        em.calllog.append(('634273', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x634273, free34)


def _args(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    flags = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])
    return [o, flags]


S(0x51aa70, 'ZVehicleIf::~ZVehicleIf (high) thiscall', 'thiscall', None, ret='eax', gen=_args, setup=_setup,
  note='unclaimed-04 batch 10; free 0x634273 is a logging hook (GUESS); base dtor 0x519430 is original code')
