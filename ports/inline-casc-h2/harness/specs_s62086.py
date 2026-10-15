from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    existing = r.choice([0, 0, rnd(c, 0x30)])
    if existing:
        vtobj = obj(c, 0x30, {0x24: pystub(c, 0, this=True, pop=0,
            side=lambda emu, k: emu.calllog.append(('existing', emu.reg('ecx'))))})
        e.w32(existing, e.r32(vtobj))
    e.w32(0x713f04, existing)
    created = rnd(c, 0x30)
    alloc_ret = r.choice([0, created])
    hook_rec(c, 0x41e290, 1, ret=alloc_ret, pop=0,
        side=lambda emu, k: emu.calllog.append(('alloc', emu.arg32(0))))
    hook_rec(c, 0x5577d0, 0, this=True, pop=0,
        side=lambda emu, k: emu.calllog.append(('init', emu.reg('ecx'))))
    return []


S(0x557930, 'GUESS initialize global resource singleton', 'cdecl', None,
  ret='eax', gen=gen, note='batch62086')
