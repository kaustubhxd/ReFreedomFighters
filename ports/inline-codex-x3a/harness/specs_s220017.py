"""Focused outer/inner resource-pool fixture for 0x495fd0."""
from pilot import S
from recruits_util import clear_hooks, logger, obj, pystub, rnd


def g495fd0(c):
    """Exercise empty/missing, exhausted, and successful resource allocations."""
    clear_hooks(c)
    e = c.emu
    mode = c.case % 7
    keys = (0x101, 0x202, 0x303)
    variants = (0x11, 0x22, 0x33)
    geom = rnd(c, 0x60)
    self_ = obj(c, 0x50, {
        0x00: pystub(c, 3, this=True),
        0x0c: pystub(c, 0, this=True, ret=geom),
    }, nslots=4)
    table = rnd(c, 12 * 3)
    subs = rnd(c, 8 * 12)
    for i, key in enumerate(keys):
        e.w32(table + i * 12 + 0, key)
        e.w32(table + i * 12 + 4, i * 3)
        e.w32(table + i * 12 + 8, 3)
        for j, variant in enumerate(variants):
            at = subs + (i * 3 + j) * 8
            e.w32(at + 0, variant)
            e.w32(at + 4, 1 + ((i + j) % 3))
    e.w32(self_ + 0x40, table)
    e.w32(self_ + 0x44, subs)
    e.w32(self_ + 0x48, 3)
    logger(c, 4)

    name = c.rng.getrandbits(32)
    if mode == 0:
        e.w32(self_ + 0x48, 0)
        resource, variant = keys[0], variants[0]
    elif mode == 1:
        resource, variant = 0xdeadbeef, variants[0]
    elif mode == 2:
        resource, variant = keys[1], 0x777
    elif mode == 3:
        resource, variant = keys[2], variants[1]
        e.w32(subs + (2 * 3 + 1) * 8 + 4, 0)
    elif mode == 4:
        resource, variant = keys[0], variants[0]
    elif mode == 5:
        resource, variant = keys[2], variants[2]
    else:
        resource, variant = keys[1], variants[1]
    return [self_, name, resource, variant]


S(0x495fd0, 'ZGeomBuffer::AllocResourceGeom', 'thiscall', None,
  ret='eax', gen=g495fd0,
  note='batch220017; outer/inner lookup, exhaustion logging, and slot allocation')
