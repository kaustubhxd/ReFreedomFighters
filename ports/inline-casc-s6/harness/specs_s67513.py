"""specs_s67513.py - cascade s6 batch 67513 (0x5d5400, thiscall(), plain ret). The 64-bit divide helper 0x634290 (__alldiv, stdcall 4 dwords, edx:eax result) is a Python hook doing the
signed division (the end time never equals the start time: a zero divisor would trap in the original); the engine word at +0x40 is the clock, +0x4c / +0x50 the end / start times,
+0x54 the state (0..3); the faded object has slots 0x250 and 0xbc."""
from pilot import S
from unicorn.x86_const import UC_X86_REG_EDX
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g5d5400(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alldiv(em, res_):
        nl, nh, dl, dh = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        n = (nh << 32) | nl
        d = (dh << 32) | dl
        if n >= 1 << 63:
            n -= 1 << 64
        if d >= 1 << 63:
            d -= 1 << 64
        em.calllog.append(('alldiv', n, d))
        q = int(abs(n) // abs(d)) * (1 if (n < 0) == (d < 0) else -1)
        q &= (1 << 64) - 1
        em.mu.reg_write(UC_X86_REG_EDX, q >> 32)
        em.ret(eax=q & 0xffffffff, argbytes=16)
    e.hook(0x634290, alldiv)
    so = sysobj(c)
    start = r.randrange(0, 5000)
    span = r.choice([1, 2, 100, 1000, 0x1000, -50 & 0xffffffff, 0x7fffff])
    end = (start + span) & 0xffffffff
    if end == start:
        end = start + 1
    now = r.choice([start, start + 1, end, end + 1, (start + end) // 2, start - 5, r.randrange(0, 20000)]) & 0xffffffff
    e.w32(so + 0x40, now)
    fobj = obj(c, 0x20, {0x250: pystub(c, 1, this=True), 0xbc: pystub(c, 1, this=True)})
    t = rnd(c, 0x80)
    e.w32(t + 0x44, fobj)
    e.w32(t + 0x4c, end)
    e.w32(t + 0x50, start)
    e.w32(t + 0x54, r.choice([0, 1, 1, 2, 2, 3]))
    return [t]


S(0x5d5400, 'GUESS fade_step', 'thiscall', None, ret=None, gen=_g5d5400, note='batch67513')
