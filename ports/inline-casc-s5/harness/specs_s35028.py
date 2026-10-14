"""specs_s35028.py - 0x656820 (thiscall(node, name) ret 8, returns eax). Chain of 0..4 nodes; this slot 0xc returns the record (word +4 flags with the 0x7ff bits clear in a third, next pointer +8);
name is null in 1/6, else one of "*", "a", "A", random text (the string at 0x678d04 is "*"); _stricmp stubbed in Python (logs both strings, case-insensitive compare); engine +0x1aa3 (unaligned) object slot 0x80
(1 arg, returns an object or 0); 0x4cc850 hooked as a fastcall recorder (ecx, edx) returning zero in 1/3 of the calls."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g656820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x10) for _ in range(n)]
    recs = [rnd(c, 0x10) for _ in range(n)]
    for i, rc in enumerate(recs):
        fl = r.getrandbits(16)
        if r.random() < 1 / 3:
            fl &= ~0x7ff
        if r.random() < 0.3:
            fl = r.choice([0x400, 0x800, 0x8000, 0x1, 0x7ff, 0x400 | 0x8000])
        e.wbytes(rc + 4, fl.to_bytes(2, 'little'))
        e.w32(rc + 8, nodes[i + 1] if i + 1 < n else 0)
    me = obj(c, 0x20, {0xc: pystub(c, 1, this=True, ret=lambda em, k: recs[min(k, max(n - 1, 0))] if n else 0)}, nslots=8)
    if r.random() < 1 / 6:
        name = 0
    else:
        name = rnd(c, 0x10)
        txt = r.choice([b'*', b'a', b'A', bytes(r.choice(b'abcXYZ*') for _ in range(r.randint(1, 5)))]) + b'\0'
        e.wbytes(name, txt)

    def stricmp(em, res_):
        def rd(p):
            d = b''
            while len(d) < 64:
                b = bytes(em.rbytes(p + len(d), 1))
                if b == b'\0':
                    break
                d += b
            return d
        a, b = rd(em.arg32(0)), rd(em.arg32(1))
        em.calllog.append(('_stricmp', a, b))
        x, y = a.lower(), b.lower()
        em.ret(eax=0 if x == y else (1 if x > y else 0xffffffff))
    e.stub_import('_stricmp', stricmp)
    cnt = [0]
    pat = [r.random() < 1 / 3 for _ in range(8)]

    def h4cc(em, rr):
        k = cnt[0]
        cnt[0] += 1
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=0 if pat[k % 8] else 1)
    e.hook(0x4cc850, h4cc)
    cnt2 = [0]
    objs = [0 if r.random() < 1 / 3 else rnd(c, 0x40) for _ in range(8)]
    tabo = obj(c, 0x10, {0x80: pystub(c, 1, this=True, ret=lambda em, k: objs[k % 8])}, nslots=0x24)
    so = sysobj(c, table_size=0x20)
    e.wbytes(so + 0x1aa3, tabo.to_bytes(4, 'little'))
    return [me, nodes[0] if n else 0, name]


S(0x656820, 'GUESS find node in chain by name', 'thiscall', None, ret='eax', gen=_g656820, note='batch35028')
