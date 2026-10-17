"""specs_s246002.py - w4d batch 246002: 0x43ae00."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def g43ae00(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    THIS = rnd(c, 0x1300)
    OUT = rnd(c, 0x20)
    OVT = rnd(c, 0x40)
    em.w32(OUT, OVT)

    def sout(emu, k):
        a = emu.arg32(0)
        s = emu.rbytes(a + 4, 0x7c).split(b'\0')[0]
        emu.calllog.append(('out', emu.reg('ecx') - OUT, emu.r32(a), s.hex(), emu.rbytes(a + 0x80, 1).hex(), emu.r32(a + 0xfc), emu.arg32(1)))
    em.w32(OVT + 0x10, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, stackmark=(0,), side=sout))

    def make_iter(items, tag):
        vt = rnd(c, 0x80)
        o = rnd(c, 0x10)
        em.w32(o, vt)
        st = [0]

        def s4c(emu, k):
            st[0] = 0
            emu.calllog.append((tag, 'reset', emu.reg('ecx') - o))

        def s5c(emu, k):
            i = st[0]
            st[0] += 1
            if i < len(items):
                emu.w32(emu.arg32(0), 1)
                emu.calllog.append((tag, 'next', i, emu.reg('ecx') - o))
                return items[i]
            emu.w32(emu.arg32(0), 0)
            emu.calllog.append((tag, 'end', emu.reg('ecx') - o))
            return r.getrandbits(32)
        em.w32(vt + 0x4c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s4c))
        em.w32(vt + 0x5c, pystub(c, 1, ret=s5c, pop=4, this=True, stackmark=(0,)))
        return o

    nodes = []
    for j in range(r.choice([0, 1, 2, 3, 4])):
        nd = rnd(c, 0x40)
        nm = rnd(c, 0x80)
        em.wbytes(nm, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 5, 20, 100]))) + b'\0')
        em.w32(nd + 8, nm)
        em.wbytes(nd + 0x10, bytes([r.choice([0, 0, 1, 7])]))
        em.wbytes(nd + 0x22, bytes([r.choice([0, 0, 1, 255])]))
        if r.random() < 0.8:
            els = []
            for _ in range(r.choice([0, 1, 2, 3])):
                e = rnd(c, 12)
                if r.random() < 0.5:
                    em.w32(e + 4, 0)
                    em.w32(e + 4, 0)
                # element pointer = e+4 ; its first dword (e+4) is zero or not
                els.append(e + 4)
            inner = make_iter(els, 'in%d' % j)
            em.w32(nd + 0x19, inner)
        else:
            em.w32(nd + 0x19, 0)
        nodes.append(nd)
    # element first dword zero/non-zero decided above randomly: make explicit
    if r.random() < 0.1:
        em.w32(THIS + 0x1214, 0)
    else:
        em.w32(THIS + 0x1214, make_iter(nodes, 'it'))
    hook_rec(c, 0x43ad20, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True,
             side=lambda emu, k: emu.calllog.append(('f43ad20', emu.reg('ecx'), emu.arg32(0) - OUT)))
    return [THIS, OUT]


S(0x43ae00, 'GUESS FUN_43ae00', 'thiscall', None, ret='al', gen=g43ae00, note='batch246002')


def g621f60(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    A = rnd(c, 0x80)
    vals = [0, 1, 9, 0xa, 0x20, 0x41, 0x7f, 0x80, 0xff, 0x100, 0xd7ff, 0xd800, 0xdbff, 0xdfff, 0xe000, 0xfffd, 0xfffe, 0xffff, 0x10000, 0x10ffff, 0x110000, 0x1fffff]
    v = r.choice(vals) if r.random() < 0.6 else r.randrange(0, 0x120000) if r.random() < 0.5 else r.randrange(0, 300)
    m = r.random()
    if m < 0.45:
        body = ('x' + r.choice(['%x', '%X']) % v) if r.random() < 0.9 else 'x'
    elif m < 0.8:
        body = '%d' % v
    else:
        chars = b'0123456789abcdefABCDEFxgG:/@`{ \x80\xff'
        body = ''.join(chr(r.choice(chars)) for _ in range(r.randrange(0, 9)))
        if r.random() < 0.5:
            body = 'x' + body
    if r.random() < 0.1:
        body = body.replace('x', '', 1) if r.random() < 0.5 else body + 'q'
    data = bytes(r.choice(b'&#ab') for _ in range(2)) + body.encode('latin-1') + b';' + bytes(r.getrandbits(8) for _ in range(8))
    em.wbytes(A, data)
    return [r.getrandbits(32), A]


S(0x621f60, 'GUESS FUN_621f60', 'cdecl', None, ret='eax', gen=g621f60, note='batch246002')
