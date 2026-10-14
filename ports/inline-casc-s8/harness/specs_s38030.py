"""specs_s38030.py - cascade s8 batch 38030. Vector (+4 data, +0xc size 0..5) of entries -> node pointers; nodes have type (3 about 70%), name at +0xc (pool of names including the exe's default
string at 0x685220, random case), +4 / +8 fields (+8 -> a block whose first dword is read). _stricmp (IAT 0x676414) is a logged Python stub with the CRT's ASCII case folding. The `name` argument
equals one entry's name 40% of the time. 0x602d30 / 0x602ff0 hooked (the second returns an object whose +0x10 is 5 about 60% of the time, or 0); the sink object has a recording slot 0 (2 args);
the engine table slot 0x58 returns a random handle; the assert hook is always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g601810(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def h(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (sa, sb)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', h))
    dflt = _cstr(e, 0x685220)
    names = [b'alpha', b'beta', b'gamma', dflt, dflt]

    def mkstr(s):
        s = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.3) else ch for ch in s)
        p = e.alloc(len(s) + 1, 1)
        e.wbytes(p, s + b'\0')
        return p
    n = r.choice([0, 1, 2, 3, 4, 5])
    entries = []
    chosen = []
    for _ in range(n):
        nd = rnd(c, 0x20)
        e.w32(nd, 3 if r.random() < 0.7 else r.choice([0, 1, 2, 4]))
        nm = r.choice(names)
        chosen.append(nm)
        e.w32(nd + 0xc, mkstr(nm))
        blk = rnd(c, 0x10)
        e.w32(nd + 8, blk)
        ent = e.alloc(4, 4)
        e.w32(ent, nd)
        entries.append(ent)
    data = e.alloc(4 * max(n, 1) + 4, 4)
    for i, ent in enumerate(entries):
        e.w32(data + 4 * i, ent)
    me = rnd(c, 0x20)
    e.w32(me + 4, data)
    e.w32(me + 0xc, n)
    if chosen and r.random() < 0.4:
        nm = r.choice(chosen)
    else:
        nm = r.choice([b'delta', b'ALPHA', b'zzz'])
    a = mkstr(nm)
    import os
    if os.environ.get('DBG'):
        print('CASE', n, chosen, nm, [hex(e.r32(en)) for en in entries], [e.r32(e.r32(en)) for en in entries])
    keyref = rnd(c, 8)
    r2 = rnd(c, 0x20)
    e.w32(r2 + 0x10, 5 if r.random() < 0.8 else r.getrandbits(32))
    hook_rec(c, 0x602d30, 1, pop=4, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x602ff0, 0, this=True, ret=lambda em, k: r2 if r.random() < 0.8 else 0)
    sink = obj(c, 0x20, {0: pystub(c, 2, this=True)})
    sysobj(c, {}, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    return [me, a, keyref, sink]


S(0x601810, 'GUESS find named node and call sink', 'thiscall', None, ret=None, gen=_g601810, note='batch38030')
