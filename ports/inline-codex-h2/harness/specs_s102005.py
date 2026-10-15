from pilot import S
from recruits_util import obj, rnd, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng

    # The lookup key is returned by 0x5003d0 through a pointer to a stable key.
    key = r.getrandbits(32)
    keyp = rnd(c, 4)
    e.w32(keyp, key)
    setup = rnd(c, 8)
    e.w32(setup + 4, r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, ret=keyp, pop=4, this=True)

    mode = r.randrange(4)
    if mode == 0:
        # Exercise logging on miss; both logger slots record their arguments.
        logger = rnd(c, 0x40)
        log2 = pystub(c, 2, ret=logger, pop=8, this=True)
        log3 = pystub(c, 2, ret=0, pop=8, this=True)
        vt = e.alloc(0x30, 4)
        e.w32(vt + 0x20, log2)
        e.w32(vt + 0x2c, log3)
        e.w32(logger, vt)
        sysobj(c, table_slots={0x54: pystub(c, 1, ret=0, pop=4, this=True)})
        e.w32(0x700390, logger)
        owner = rnd(c, 0x20)
    else:
        # A table hit exercises all stream and conversion helpers.
        resource = rnd(c, 0x20)
        e.w32(resource, r.getrandbits(32))
        sysobj(c, table_slots={0x54: pystub(c, 1, ret=resource, pop=4, this=True)})

        stream84 = pystub(c, 1, ret=0, pop=4, this=True,
                          side=lambda emu, k: [emu.w32(emu.arg32(0) + 4*i, r.getrandbits(32)) for i in range(4)])
        stream7c = pystub(c, 2, ret=0, pop=8, this=True, deref={0: 19, 1: 4})
        stream = obj(c, 0x100, {0x84: stream84, 0x7c: stream7c})
        owner = rnd(c, 0x20)
        e.w32(owner + 0xc, stream)

        hook_rec(c, 0x4db670, 1, ret=0, pop=4, this=True,
                 deref={0: 4})
        hook_rec(c, 0x43e960, 0, ret=0, pop=0,
                 side=lambda emu, k: [emu.w32(emu.reg('ecx') + i*4,
                                                emu.r32(emu.reg('ecx') + i*4) ^ emu.r32(emu.reg('edx') + i*4))
                                      for i in range(4)])
        hook_rec(c, 0x4de040, 1, ret=0, pop=4, this=True,
                 side=lambda emu, k: [emu.w32(emu.reg('ecx') + i*4,
                                                emu.r32(emu.reg('edx') + i*4) + 0x1020304 + i)
                                      for i in range(19)])

    e.w32(0x6f5630, r.getrandbits(32))
    e.w32(0x7003b0, pystub(c, 0, ret=0, pop=0))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0)
    return [owner, setup]


S(0x501720, 'GUESS_read_transform_stream_record', 'thiscall', None,
  ret=None, gen=gen, note='batch102005')
