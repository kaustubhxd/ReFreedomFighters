"""specs_s90004.py - hard trial (fable) batch 90004: 0x605ba0 type-list parser. Same model as batch 90003: the begin/end/cap string helpers and
the two case-insensitive set searches run real; allocator object at 0x70038c = deterministic bump alloc / logged free; memmove + memcpy stubbed;
registry global [0x724694] set (0x602d30 runs real); registry lookup 0x602ff0 hooked (logs the name, returns one of 4 type objects or 0 by the
name's length); vector grow 0x5f4630 real. Texts are random mixes of names, spaces, tabs, newlines and commas."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, stub_memmove, _HOOKED


def _cstr(em, p, limit=0x200):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


WORDS = [b'int', b'float', b'string', b'Vec3', b'INT', b'bool', b'x', b'quat', b'foo_bar']


def _text(r):
    k = r.random()
    if k < 0.08:
        return b''
    if k < 0.16:
        return r.choice([b' ', b'\n', b',', b' ,', b'int', b' int', b'\tfloat\n', b'  a  ', b', ,', b' int\n', b' int,float', b' a\n\nb'])
    out = b''
    for _ in range(r.randint(1, 7)):
        out += r.choice([b' ', b' ', b'\t', b'\n', b',', b' ,', b', ', b'\n\n', b'']) + r.choice(WORDS + [b'', b'zz'])
    return out + r.choice([b'', b' ', b'\n', b','])


def _g605ba0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memmove(c)

    def memcpy(em, res_):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n:
            em.wbytes(d, em.rbytes(s_, n))
        em.ret(eax=d, argbytes=0)
    e.stub_import('memcpy', memcpy)

    def ah(em, res_):
        em.calllog.append(('assert',))
        em.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def alloc(em, res_):
        n = em.arg32(0)
        p = em.alloc(n, 4)
        em.calllog.append(('alloc', n, p))
        em.ret(eax=p, argbytes=4)

    def free(em, res_):
        em.calllog.append(('free', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.w32(0x70038c, obj(c, 0x10, {8: e.stub_fn('alloc', alloc), 0x10: e.stub_fn('free', free)}))

    types = [rnd(c, 0x20) for _ in range(4)]
    reg = rnd(c, 0x20)
    e.w32(0x724694, reg)

    def lookup(em, res_):
        name = _cstr(em, em.arg32(0))
        em.calllog.append(('lookup', em.reg('ecx'), name))
        em.ret(eax=0 if len(name) % 3 == 0 else types[len(name) % 4], argbytes=4)
    e.hook(0x602ff0, lookup)
    _HOOKED.add(0x602ff0)

    cap = r.choice([1, 2, 4, 8])
    cnt = r.randint(0, cap)
    arr = rnd(c, cap * 4)
    self_ = rnd(c, 0x20)
    e.w32(self_, arr)
    e.w32(self_ + 4, cap)
    e.w32(self_ + 8, cnt)
    t = _text(r)
    ta = e.alloc(len(t) + 1, 1)
    e.wbytes(ta, t + b'\0')
    return [self_, ta]


S(0x605ba0, 'GUESS type-list parser append', 'thiscall', None, ret=None, gen=_g605ba0, note='batch90004')
