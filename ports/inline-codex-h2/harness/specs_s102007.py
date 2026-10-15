from pilot import S
from recruits_util import obj, rnd, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng

    cells = [rnd(c, 8) for _ in range(3)]
    values = [r.uniform(-1000.0, 1000.0) for _ in range(3)]
    for p, v in zip(cells, values):
        e.w32(p, __import__('struct').unpack('<I', __import__('struct').pack('<f', v))[0])
    hook_rec(c, 0x5003d0, 1, ret=lambda emu, k: cells[emu.arg32(0)], pop=4, this=True)

    resource = rnd(c, 0x20)
    e.w32(resource, r.getrandbits(32))
    stream_words = [r.getrandbits(32) for _ in range(7)]

    def fill_stack(emu, k):
        p = emu.arg32(0)
        for i, x in enumerate(stream_words):
            emu.w32(p + 4*i, x)

    hook_rec(c, 0x4db500, 1, ret=0, pop=4, this=True, side=fill_stack)
    read_values = [r.getrandbits(32) for _ in range(7)]

    def read_stream(emu, k):
        p = emu.arg32(0)
        for i, x in enumerate(read_values):
            emu.w32(p + 4*i, x)

    slot84 = pystub(c, 1, ret=0, pop=4, this=True, deref={0: 7}, side=read_stream)
    slot5d0 = pystub(c, 0, ret=(resource if r.randrange(4) else 0), pop=0, this=True)
    manager = obj(c, 0x20, {0x84: slot84, 0x5d0: slot5d0})
    e.w32(manager + 8, rnd(c, 0x20))
    owner = rnd(c, 0x40)
    e.w32(owner + 0x1c, manager)

    ret_float = r.uniform(-100.0, 100.0)
    hook_rec(c, 0x52b330, 2, ret=0, pop=8, this=True,
             deref={0: 7, 1: 4}, st0=ret_float)
    hook_rec(c, 0x602cd0, 1, ret=0, pop=4, this=True)
    hook_rec(c, 0x500360, 1, ret=0, pop=4, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0)

    arg = rnd(c, 0x10)
    e.w32(arg + 4, rnd(c, 0x20))
    e.w32(arg + 8, rnd(c, 0x20))
    e.w32(0x6f5630, r.getrandbits(32))
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    return [owner, arg]


S(0x558ef0, 'GUESS_update_indexed_stream_value', 'thiscall', None,
  ret=None, gen=gen, note='batch102007')
