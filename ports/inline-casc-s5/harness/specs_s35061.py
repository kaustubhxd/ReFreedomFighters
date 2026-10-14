"""specs_s35061.py - 0x432560 (thiscall(name, skip) ret 8, ret='eax'). Embedded list object at this+0x84 (slots 0x4c, 0x64: 0..4 entry blocks, then 0; entry dword 0 is what the real 0x4cc1d0 returns);
skip is null in a quarter, one of the entries in half, else random; 0x4cc850 hooked as a fastcall recorder (ecx, edx) returning zero (a name match) per call by a random pattern; 0x4cc1d0 runs as exe code."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g432560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ents = [rnd(c, 8) for _ in range(r.choice([0, 1, 2, 3, 4]))]
    pat = [r.random() < 0.5 for _ in range(8)]
    cnt = [0]

    def h(em, rr):
        k = cnt[0]
        cnt[0] += 1
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=0 if pat[k % 8] else r.getrandbits(32) | 1)
    e.hook(0x4cc850, h)
    vo = obj(c, 4, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                    0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ents[k] if k < len(ents) else 0)}, nslots=0x1a)
    me = rnd(c, 0x90)
    e.w32(me + 0x84, e.r32(vo))
    t = r.random()
    skip = 0 if t < 0.25 else (r.choice(ents) if (t < 0.75 and ents) else r.getrandbits(32))
    name = rnd(c, 0x10)
    return [me, name, skip]


S(0x432560, 'GUESS find next entry with matching name', 'thiscall', None, ret='eax', gen=_g432560, note='batch35061')
