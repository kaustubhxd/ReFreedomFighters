"""specs_s1055.py - unclaimed-04 batch 55 (docs/20-unclaimed-04.md): 0x65f070 (thiscall, one argument, ret 4).
GUESS: list processor. The helper is hooked by address."""
from pilot import S


def _helper_log(c, name):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    return h


def _setup(c):
    # Hook the helper function by address
    c.emu.hook(0x63d2f0, _helper_log(c, 'helper63d2f0'))


def _args(c):
    # Create object with two parallel arrays and count
    size = 0x200
    obj = c.emu.alloc(size, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(size)))

    # Set up count at obj+0x44
    count = c.rng.randint(0, 3)
    c.emu.w32(obj + 0x44, count)

    # Set up first array at obj+0x48
    for i in range(count):
        c.emu.w32(obj + 0x48 + i * 4, c.rng.getrandbits(32) | 1)  # non-zero values

    # Set up second array at obj+0x58
    for i in range(count):
        c.emu.w32(obj + 0x58 + i * 4, c.rng.getrandbits(32))

    # Create and set up the global manager object
    manager = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(manager, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))

    # Set manager at global 0x70039c
    c.emu.w32(0x70039c, manager)

    return [obj]


S(0x65f070, 'unknown::list_processor (unknown) thiscall', 'thiscall', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 55; helper hooked by address (GUESS)')
