"""specs_s66019.py - cascade s4 batch 66019: 0x54e7e0 (/GS-protected: poll two events, read a file block and report errors)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g54e7e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    H1, H2 = 0x1111, 0x2222
    k1 = r.choice([0, 1, 2, 3])          # how many times the first wait is non-zero
    seq2 = [r.choice([0, 1, 0, 5]) for _ in range(8)]
    cnt = {'w1': 0, 'w2': 0}

    def wait(em, rr):
        h, t = em.arg32(0), em.arg32(1)
        if h == H1:
            k = cnt['w1']
            cnt['w1'] += 1
            v = 1 if k < k1 else 0
        else:
            k = cnt['w2']
            cnt['w2'] += 1
            v = seq2[k % 8]
        em.calllog.append(('Wait', h, t, v))
        em.ret(eax=v, argbytes=0)
    e.stub_import('WaitForSingleObject', wait)

    def fseek(em, rr):
        em.calllog.append(('fseek', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)

    def fread(em, rr):
        em.calllog.append(('fread', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=r.choice([-1, -1, 0, 5]) & 0xffffffff, argbytes=0)
    e.stub_import('fseek', fseek)
    e.stub_import('fread', fread)
    err = r.getrandbits(8)

    def gle(em, rr):
        em.calllog.append(('GetLastError',))
        em.ret(eax=err, argbytes=0)

    def fm(em, rr):
        em.calllog.append(('FormatMessage', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(5), em.arg32(6)))
        em.wbytes(em.arg32(4), b'msg%02x\0\0' % (em.arg32(2) & 0xff))
        em.ret(eax=5, argbytes=28)

    def rst(em, rr):
        em.calllog.append(('ResetEvent', em.arg32(0)))
        em.ret(eax=1, argbytes=4)

    def slp(em, rr):
        em.calllog.append(('Sleep', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.stub_import('GetLastError', gle)
    e.stub_import('FormatMessageA', fm)
    e.stub_import('ResetEvent', rst)
    e.stub_import('Sleep', slp)

    def pr(em, rr):                       # log object slot 0x2c: cdecl (o, fmt, name, msg)
        em.calllog.append(('log', em.arg32(1), em.arg32(2), bytes(em.rbytes(em.arg32(3), 8))))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x40, {0x2c: e.stub_fn('print', pr)})
    lg = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=lo)})
    e.w32(0x700390, lg)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    a = e.alloc(0x300, 8)
    e.w32(a + 0x2ce, H2)
    e.w32(a + 0x2d2, H1)
    e.w32(a + 0x2d6, r.getrandbits(32))
    e.w32(a + 0x2da, r.getrandbits(32))
    e.w32(a + 0x2de, rnd(c, 8))
    e.w32(a + 0x2e6, r.getrandbits(16))
    e.wbytes(a + 0x1ca, b'name\0')
    return [a]


S(0x54e7e0, 'GUESS /GS reader loop over two events', 'stdcall', None, ret='eax', gen=_g54e7e0, note='batch66019')
