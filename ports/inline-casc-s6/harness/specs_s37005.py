"""specs_s37005.py - cascade s6 batch 37005: 0x50dfa0 (find entry by name). Hooked: 0x5003d0 (returns node 1 then node 2), 0x50d7b0, _stricmp (IAT 0x676414, logged),
logger object at 0x700390 (slot 0x20 returns an object with cdecl slot 0x2c), assert hook 0x7003b0 always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

WORDS = [b'tank', b'Heli', b'SOLDIER', b'door', b'x']


def _cstr(em, p):
    out = b''
    while True:
        b = em.rbytes(p, 1)
        if b == b'\0' or len(out) > 64:
            return out
        out += b
        p += 1


def _g50dfa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def h(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (a, b)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', h))
    words = []
    for w in WORDS:
        p = e.alloc(len(w) + 1, 1)
        e.wbytes(p, w + b'\0')
        words.append(p)
    # logger
    Lg = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})
    lgr = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)})
    e.w32(0x700390, lgr)
    # node 1
    X1 = rnd(c, 0x10)
    ty = r.choice([3, 3, 4, 4, 0, 1, 2, 7])
    e.wbytes(X1 + 4, bytes([ty]))
    if ty == 3:
        e.w32(X1, r.choice(words))
    else:
        e.w32(X1, obj(c, 0x10, {0x34: pystub(c, 0, this=True, ret=r.choice(words))}))
    X2 = rnd(c, 0x10)
    e.wbytes(X2 + 4, bytes([r.choice([0, 1, 1, 2, 5, r.getrandbits(8)])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: [X1, X2][min(k, 1)])
    hook_rec(c, 0x50d7b0, 1, this=True, deref={0: 1})
    # table
    Rs = []
    for _ in range(4):
        R = rnd(c, 0x10)
        e.w32(R + 4, 0 if r.random() < 0.2 else r.choice(words))
        Rs.append(R)
    Ts = [obj(c, 0x10, {0x20: pystub(c, 0, this=True, ret=lambda em, k: Rs[k % 4])}) for _ in range(4)]
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: 0 if k % 5 == 3 else Ts[k % 4])}, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    lst = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), r.choice([0, 1, 1, 5]))),
                        0x5c: pystub(c, 1, this=True, nullflag=(0,), ret=lambda em, k: r.getrandbits(32),
                                     side=lambda em, k: em.w32(em.arg32(0), 0 if (k >= 5 or r.random() < 0.35) else 1))})
    ent = rnd(c, 0x30)
    e.w32(ent + 0x18, lst if r.random() < 0.9 else 0)
    M = obj(c, 0x300, {0x25c: pystub(c, 2, this=True, ret=ent if r.random() < 0.9 else 0)})
    e.w32(tab + 0xadc, M)
    a = rnd(c, 0x10)
    return [a]


S(0x50dfa0, 'GUESS find entry by name then update node', 'stdcall', None, ret=None, gen=_g50dfa0, note='batch37005')
