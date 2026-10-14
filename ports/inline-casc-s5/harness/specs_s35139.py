"""specs_s35139.py - 0x602160 (stdcall(a, s) ret 8, ret='eax'). s: C string of length 0..12, or around the limit (999, 1000, 1001, 1005); strncpy stubbed (IAT, logs the source string and length, copies exactly n bytes, no terminator);
0x4cc850 hooked in Python as a fastcall (ecx, edx) that logs ecx and the pattern string it receives in edx and returns a call-dependent value."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g602160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ret = r.getrandbits(32)

    def rds(em, p, n=1100):
        s = b''
        while len(s) < n:
            ch = bytes(em.rbytes(p + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        return s

    def sncpy(em, rr):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        src = rds(em, s)
        em.calllog.append(('strncpy', src, n))
        em.wbytes(d, (src[:n] + bytes(max(0, n - len(src))))[:n])
        em.ret(eax=d)

    def h(em, rr):
        em.calllog.append(('4cc850', em.reg('ecx'), rds(em, em.reg('edx'))))
        em.ret(eax=ret)
    e.stub_import('strncpy', sncpy)
    e.hook(0x4cc850, h)
    ln = r.choice([0, 1, 5, 12, 999, 1000, 1001, 1005])
    s = rnd(c, 0x420)
    e.wbytes(s, bytes(r.choice(b'abcXYZ019') for _ in range(ln)) + b'\0')
    return [r.getrandbits(32), s]


S(0x602160, 'GUESS match name against star pattern', 'stdcall', None, ret='eax', gen=_g602160, note='batch35139')
