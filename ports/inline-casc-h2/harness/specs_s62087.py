from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    src = rnd(c, 0x40)
    for off in range(0x18, 0x34, 4):
        e.w32(src + off, r.getrandbits(32))
    allowed = r.choice([0, 0x100, 0x101, 1, 0x80000000])
    source = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, pop=4, ret=allowed,
        side=lambda emu, k: emu.calllog.append(('allow', emu.reg('ecx'), emu.arg32(0))))})
    # Use the randomized source block as an object with its own vtable.
    e.w32(source, e.r32(source))
    # The source payload is the object seen by slot 0x1e0.
    source_obj = rnd(c, 0x40)
    e.w32(source_obj, e.r32(source))
    for off in range(0x18, 0x34, 4):
        e.w32(source_obj + off, e.r32(src + off))
    dest = obj(c, 0x50, {0x48: pystub(c, 1, this=True, pop=4,
        side=lambda emu, k: emu.calllog.append(('copy-init', emu.reg('ecx'), emu.arg32(0))))})
    for off in range(0x18, 0x34, 4):
        e.w32(dest + off, r.getrandbits(32))
    return [dest, source_obj]


S(0x5d8c90, 'GUESS conditionally copy state block', 'thiscall', None,
  ret='eax', gen=gen, note='batch62087')
