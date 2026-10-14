"""specs_s34132.py - 0x4ce050: iterator object with slot 0x4c (writes it[0] = 1 or 0) and slot 0x5c (returns the next name pointer; sets it[0] non-zero for the first m calls, zero afterwards);
_stricmp import stubbed in Python (case-insensitive equality; the log holds both strings); null this in a tenth. ret al."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    names = [b'Alpha', b'alpha', b'BETA', b'gamma', b'Gamma\0'[:5], b'']
    pool = []
    for _ in range(4):
        s = r.choice(names)
        t = rnd(c, 0x10)
        e.wbytes(t, s + b'\0')
        pool.append(t)
    want = r.choice(names)
    w = rnd(c, 0x10)
    e.wbytes(w, want + b'\0')
    m = r.choice([0, 1, 2, 3, 4])
    state = {'n': 0}

    def cstr(em, p):
        out = b''
        while True:
            b = bytes(em.rbytes(p, 1))
            if b == b'\0':
                return out
            out += b
            p += 1

    def init(em, k):
        state['n'] = 0
        em.w32(em.arg32(0), 1 if m > 0 else 0)

    def nxt(em, k):
        i = state['n']
        em.w32(em.arg32(0), 1 if i < m else 0)
        state['n'] = i + 1

    def ret5c(em, k):
        return pool[min(state['n'] - 1, 3)] if state['n'] else pool[0]
    me = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=init, stackmark=(0,)),
                       0x5c: pystub(c, 1, this=True, side=nxt, ret=ret5c, stackmark=(0,))}, nslots=0x60 // 4)

    def sti(em, res_):
        a, b = cstr(em, em.arg32(0)), cstr(em, em.arg32(1))
        em.calllog.append(('_stricmp', a, b))
        em.ret(eax=0 if a.lower() == b.lower() else r.choice([1, 0xffffffff]), argbytes=0)
    e.stub_import('_stricmp', sti)
    if r.random() < 0.1:
        me = 0
    return [me, w]


S(0x4ce050, 'GUESS is a name in an enumerated list', 'thiscall', None, ret='al', gen=_g, note='batch34132')
