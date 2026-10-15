from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, hook_rec

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    descriptor = r.getrandbits(32)
    released = r.getrandbits(32)
    seq = [descriptor, released]
    manager = sysobj(c, slots={0x48: pystub(c, 1, this=True, ret=lambda emu,k: seq[min(k,1)], side=lambda emu,k: emu.calllog.append(('mgr', emu.arg32(0))))})
    e.w32(0x70038c, manager)
    raw = rnd(c, 0x1000)
    hook_rec(c, 0x41e290, 1, pop=0, ret=raw, side=lambda emu,k: emu.calllog.append(('alloc', emu.arg32(0))))
    info = rnd(c, 0x30)
    e.w32(info + 0x10, r.choice([0, 1, 15, 16, 17, 31, 32, 127, 256]))
    return [info]

S(0x63a720, 'GUESS allocate and align info buffer', 'cdecl', None, ret='eax', gen=gen, note='batch62033')
