import struct
from pilot import S
from recruits_util import obj, rnd, sysobj, clear_hooks, hook_rec, pystub


def _bits(v):
    return struct.unpack('<I', struct.pack('<f', float(v)))[0]


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    me = rnd(c, 0x2000)
    n1, n2 = r.randint(1, 3), r.randint(1, 3)
    e.w32(me + 0x8c, n1)
    e.w32(me + 0x90, n2)
    for i in range(9):
        e.w32(me + 4*i, _bits(r.uniform(-3.0, 3.0)))
    # One or both first-loop records can cross the sign test.
    for i in range(n1):
        a = me + 0xfe + i*0xde
        x = r.uniform(-5.0, 5.0)
        d = r.choice([-1.0, 1.0]) * r.uniform(0.1, 2.0)
        e.w32(a, _bits(x))
        e.w32(a + 0x14, _bits(x + d))
        b = me + 0x7d1 + i*0x163
        for j in range(3): e.w32(b - 8 + 4*j, _bits(r.uniform(-10.0, 10.0)))
    for i in range(n2):
        a = me + 0x476 + i*0xde
        x = r.uniform(-5.0, 5.0)
        d = r.choice([-1.0, 1.0]) * r.uniform(0.1, 2.0)
        e.w32(a, _bits(x))
        e.w32(a + 0x14, _bits(x + d))
        b = me + 0xd5d + i*0x133
        for j in range(3): e.w32(b - 8 + 4*j, _bits(r.uniform(-10.0, 10.0)))

    logger = rnd(c, 0x40)
    log_start = pystub(c, 2, ret=logger, pop=8, this=True)
    log_finish = pystub(c, 2, ret=0, pop=0, this=True)
    vt = e.alloc(0x30, 4)
    e.w32(vt + 0x20, log_start)
    e.w32(vt + 0x2c, log_finish)
    e.w32(logger, vt)
    e.w32(0x700390, logger)
    so = sysobj(c, table_size=0xb00)
    table = e.r32(so + 0x9b)
    table_child = obj(c, 0x20, {0x2e0: pystub(c, 5, ret=0, pop=20, this=True)})
    e.w32(table + 0xadc, table_child)
    e.w32(0x6f5630, r.getrandbits(32))
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0)
    return [me]


S(0x524de0, 'GUESS_transform_two_float_record_sets', 'thiscall', None,
  ret=None, gen=gen, note='batch102012')
