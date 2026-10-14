"""specs_s35163.py - 0x4d68e0 (stdcall(date, tim) ret 8, ret=None). IAT 0x676438 (_time32, cdecl, 1 arg: writes a random t and logs the call) and 0x67643c (_localtime32, cdecl, recorded with the dword at its argument): returns a 0x24-byte struct tm with fields mostly in range
(sec 0..61, min 0..59, hour 0..23, mday 1..31, mon 0..11, year 70..140) and garbage in 1/5 of the fields. date: null in half, else a 4-byte block; tim: word zero in 30%, else random non-zero."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _g4d68e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = r.getrandbits(32)

    def tmh(em, res_):
        p = em.arg32(0)
        em.calllog.append(('_time32', p != 0))
        em.w32(p, t)
        em.ret(eax=t, argbytes=0)
    tmb = rnd(c, 0x24)
    for i, (lo, hi) in enumerate([(0, 61), (0, 59), (0, 23), (1, 31), (0, 11), (70, 140)]):
        e.w32(tmb + 4 * i, r.randint(lo, hi) if r.random() < 0.8 else r.getrandbits(32))
    e.w32(0x676438, e.stub_fn('_time32', tmh))
    e.w32(0x67643c, pystub(c, 1, ret=tmb, pop=0, deref={0: 1}))
    d = 0 if r.random() < 0.5 else rnd(c, 4)
    w = rnd(c, 4)
    e.wbytes(w, (0 if r.random() < 0.3 else r.randint(1, 0xffff)).to_bytes(2, 'little'))
    return [d, w]


S(0x4d68e0, 'GUESS pack local date and time into DOS words', 'stdcall', None, ret=None, gen=_g4d68e0, note='batch35163')
