"""specs_s35108.py - 0x427dc0 (stdcall(path) ret 4, ret='eax'). KERNEL32 CreateFileA (7 args, all logged, the path string read) and SetFilePointer (4 args logged) stubbed in Python: CreateFileA returns -1 in a third (else a random handle), SetFilePointer returns -1 in a third;
logger at 0x700390 (slot 0x20 (2 args, line recorded) -> object with a custom slot 0x2c that logs its words and the path string)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g427dc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hv = 0xffffffff if r.random() < 1 / 3 else (r.getrandbits(32) | 0x10) & 0xfffffffe
    sv = 0xffffffff if r.random() < 1 / 3 else r.getrandbits(32) & 0x7fffffff

    def rds(em, p):
        s = b''
        while len(s) < 24:
            ch = bytes(em.rbytes(p + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        return s

    def cf(em, rr):
        em.calllog.append(('CreateFileA', rds(em, em.arg32(0)), tuple(em.arg32(i) for i in range(1, 7))))
        em.ret(eax=hv, argbytes=28)

    def sf(em, rr):
        em.calllog.append(('SetFilePointer', tuple(em.arg32(i) for i in range(4))))
        em.ret(eax=sv, argbytes=16)
    e.stub_import('CreateFileA', cf)
    e.stub_import('SetFilePointer', sf)

    def l2c(em, rr):
        em.calllog.append(('slot2c', em.reg('ecx'), em.arg32(0), em.arg32(1), rds(em, em.arg32(2))))
        em.ret(eax=0)
    lg2 = obj(c, 0x20, {0x2c: e.stub_fn('slot2c', l2c)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    p = rnd(c, 0x20)
    e.wbytes(p, bytes(r.choice(b'abc/.\\xyz') for _ in range(r.randint(0, 12))) + b'\0')
    return [p]


S(0x427dc0, 'GUESS open file for append with error logs', 'stdcall', None, ret='eax', gen=_g427dc0, note='batch35108')
