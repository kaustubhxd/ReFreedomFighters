"""specs_s36027.py - cascade s4 batch 36027: 0x57def0 (command dispatcher), 0x589710 (copy a record), 0x41eca0 (remove list entry by name), 0x44d250 (cache lookup with eviction), 0x428370 (write buffer to a file with error report)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memmove


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _cstr(em, p, limit=0x80):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


def _g57def0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x57ece0, 1, this=True)
    hook_rec(c, 0x562c20, 1, this=True)
    hook_rec(c, 0x57d000, 0, this=True)
    hook_rec(c, 0x57e930, 0, this=True)

    def mc(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(d, em.rbytes(s_, n))
        em.calllog.append(('memcpy', d, s_, n))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, mc)
    so = sysobj(c)
    o = rnd(c, 0x1400)
    src = rnd(c, 0x40)
    e.w32(o + 0x131c, src)
    e.wbytes(so + 0x1907, o.to_bytes(4, 'little'))
    E = e.alloc(0x400, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x400)))
    e.w32(E + 0xdc, 2 if r.random() < 0.85 else r.choice([0, 1, 3]))
    e.w32(E + 0x32c, rnd(c, 0x40))
    e.w32(E + 0x338, r.choice([0, 1, 4, 0x10, 0x20]))
    code = r.choice([0x1388, 0x1389, 0x1387, 0x1770, 0x1771, 0x2b67, 0x2b66, 0x3ea, 0x3eb, 0x3e9, 0x3ec, 0, r.getrandbits(16)])
    return [E, code]


def _g589710(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memmove(c)
    src = e.alloc(0x100, 4)
    e.wbytes(src, bytes(r.getrandbits(8) for _ in range(0x100)))
    _w32(c, src, r.choice([0, 1, 5, 12, 0xffffffff]))
    _w32(c, src + 0x38, r.choice([0, 1, 7, 16, 0xfffffffe]))
    _w32(c, src + 0x7c, r.choice([0, 1, 4, 12]))
    _w32(c, src + 0xb0, r.choice([0, 1, 3, 10]))
    E = e.alloc(0x100, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [E, src]


def _g41eca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def sic(em, rr):
        a, b = _cstr(em, em.arg32(0)), _cstr(em, em.arg32(1))
        x, y = a.lower(), b.lower()
        em.calllog.append(('stricmp', a, b))
        em.ret(eax=((x > y) - (x < y)) & 0xffffffff, argbytes=0)
    e.stub_import('_stricmp', sic)

    def fh(em, rr):
        em.calllog.append(('free', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, fh)
    names = [b'abc\0', b'ABC\0', b'xyz\0']
    nm = e.alloc(0x10, 4)
    e.wbytes(nm, r.choice(names))
    n = r.choice([0, 1, 2, 3])
    elems = []
    for i in range(n):
        el = e.alloc(0x20, 4)
        e.wbytes(el, bytes(r.getrandbits(8) for _ in range(0x20)))
        sp = e.alloc(0x10, 4)
        e.wbytes(sp, r.choice(names))
        _w32(c, el, 0 if r.random() < 0.1 else sp)
        _w32(c, el + 0xc, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
        elems.append(el)
    seq = elems + [0]
    cobj = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)), 0x44: pystub(c, 1, this=True, stackmark=(0,)),
                         0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)])})
    E = rnd(c, 0x40)
    e.w32(E + 0x20, 0 if r.random() < 0.1 else cobj)
    return [E, nm]


def _g44d250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    T = r.randint(0x200, 0x400)
    e.w32(so + 0x44, T)
    e.w32(so + 0x40, r.getrandbits(32))
    E = e.alloc(0x480, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x480)))
    n = r.choice([0, 1, 2, 5, 15, 16])
    e.w32(E + 0x46c, n)
    a, b = r.randint(1, 3), r.randint(1, 3)
    fresh = r.random() < 0.4
    for i in range(16):
        nd = e.alloc(0x50, 4)
        e.wbytes(nd, bytes(r.getrandbits(8) for _ in range(0x50)))
        _w32(c, nd, a if (r.random() < 0.2 and not fresh) else r.choice([0, 4, 5]) if fresh else r.randint(1, 3))
        _w32(c, nd + 4, b if (r.random() < 0.5 and not fresh) else r.randint(1, 3))
        age = r.randint(0, 0xff) if fresh else r.choice([0x100, 0x101, 0xff, 0x300, 0, 0x7fffffff, -5 & 0xffffffff, -0x1000 & 0xffffffff, 0x80000000])
        _w32(c, nd + 0x3c, (T - age) & 0xffffffff)
        e.w32(E + 0x1c + 4 * i, nd)
    return [E, a, b]


def _g428370(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 5, 0x3c00000, 0x3c00001, 0x7800000, 0x7800005])
    okseq = [r.choice([1, 1, 0]) for _ in range(4)]
    st = {'w': 0}

    def wf(em, rr):
        k = st['w']
        st['w'] += 1
        em.calllog.append(('WriteFile', em.arg32(0), em.arg32(2), em.arg32(4)))
        em.ret(eax=okseq[min(k, 3)], argbytes=20)
    e.stub_import('WriteFile', wf)
    err = r.getrandbits(32)

    def gle(em, rr):
        em.calllog.append(('GetLastError',))
        em.ret(eax=err, argbytes=0)
    e.stub_import('GetLastError', gle)
    msg = rnd(c, 0x20)

    def fm(em, rr):
        em.w32(em.arg32(4), msg)
        em.calllog.append(('FormatMessageA', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(5), em.arg32(6)))
        em.ret(eax=5, argbytes=28)
    e.stub_import('FormatMessageA', fm)

    def lf(em, rr):
        em.calllog.append(('LocalFree', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.stub_import('LocalFree', lf)

    def pf(em, rr):
        em.calllog.append(('print', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('printf', pf)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)}))
    return [r.getrandbits(32), rnd(c, 0x10), n]


S(0x57def0, 'GUESS command dispatcher', 'thiscall', None, ret='al', gen=_g57def0, note='batch36027')
S(0x589710, 'GUESS copy a counted record', 'thiscall', None, ret='eax', gen=_g589710, note='batch36027')
S(0x41eca0, 'GUESS remove list entry by name', 'thiscall', None, ret=None, gen=_g41eca0, note='batch36027')
S(0x44d250, 'GUESS cache lookup with eviction', 'thiscall', None, ret='eax', gen=_g44d250, note='batch36027')
S(0x428370, 'GUESS write buffer to a file with error report', 'stdcall', None, ret='al', gen=_g428370, note='batch36027')
