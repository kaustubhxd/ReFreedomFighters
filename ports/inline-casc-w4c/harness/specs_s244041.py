"""specs_s244041.py - hand-written specs for batch 244041."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
import pe_emu


def g5a1c50(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    isheap = lambda v: 0x20000000 <= v < 0x30000000

    def cs(emu, p, n=0x200):
        out = b''
        while p and len(out) < n:
            ch = bytes(emu.rbytes(p + len(out), 1))
            if ch == b'\0':
                break
            out += ch
        return out

    def lg(nm, *idx):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in idx))

    def word(n, slash=True):
        al = b'abcxyz/' if slash else b'abcxyz'
        return bytes(r.choice(al) for _ in range(n)) + b'\0'
    # --- this
    def s84(emu, k):
        emu.calllog.append(('s84', emu.reg('ecx')))
        if r.random() < 0.7:   # sometimes nothing is written: the zero initialisation of the out vector is visible
            emu.wbytes(emu.arg32(0), b''.join(pk(r.choice([0.0, 0.0, 0.5, 1.0, -1.0, 2.0])) for _ in range(3)))
    camobj = obj(c, 0x80, {0x84: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s84)})
    sub = rnd(c, 0x900)
    em.w32(sub + 0x852, rnd(c, 0x40))
    me = obj(c, 0xa00, {0x84: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s84),
                        0x684: pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=lg('t684'))})
    X = 0 if r.random() < 0.1 else rnd(c, 0x40)
    em.w32(me + 0x93a, X)
    p54 = rnd(c, 0x20)
    em.w32(me + 0x54, p54)
    arr = rnd(c, 0x40 * 4)
    for i in range(0x40):
        em.w32(arr + 4 * i, r.choice([0, 1, 7, r.getrandbits(32)]) if r.random() < 0.8 else 0)
    em.w32(me + 0x936, arr)
    em.w32(me + 0x92e, camobj)
    em.w32(me + 0x92e, sub if False else camobj)
    # the object at this[0x92e] needs [+0x852]: place the sub block pointer inside camobj's memory
    em.w32(camobj + 0x852, rnd(c, 0x40))
    # --- engine objects
    Z = rnd(c, 0x100)
    em.w32(Z + 0x7c, r.getrandbits(32))
    em.wbytes(Z + 0x70, pk(r.choice([0.0, 1.0, 2.5])))
    H = obj(c, 0x40, {0x60: pystub(c, 1, ret=lambda emu, k: 0 if r.random() < 0.15 else Z, pop=4, this=True, side=lg('h60', 0))})
    pathp = em.alloc(0x400, 4)
    # the code strips two path components and copies the tail: a tail shorter than 4 characters overflows its length arithmetic (fastfail 0x634047), so keep >= 4
    comps = [word(r.choice([0, 1, 2, 6]), False)[:-1] for _ in range(r.choice([2, 2, 3, 4]))]
    lead = b'/' if r.random() < 0.3 else b''
    S1 = lead + b'/'.join(comps) + b'/' + word(r.choice([4, 4, 5, 12, 40, 200, 240]), False)
    em.wbytes(pathp, S1)
    # Q chain: slot 0x40 -> a value, 0x1dc -> value, 0x1e8 -> path string
    def mk(slot, retf):
        return pystub(c, 1, ret=retf, pop=4, this=True, side=lg('q%x' % slot, 0))
    Q = obj(c, 0x200, {0x40: mk(0x40, lambda emu, k: 0 if r.random() < 0.1 else r.getrandbits(32) | 1),
                       0x1dc: mk(0x1dc, lambda emu, k: 0 if r.random() < 0.1 else r.getrandbits(32) | 1),
                       0x1e8: mk(0x1e8, lambda emu, k: 0 if r.random() < 0.1 else pathp)})
    G = rnd(c, 0x2000)
    em.w32(G + 0x9b, H)
    em.w32(G + 0x1a9f, Q)
    em.w32(G + 0x1b5d, r.choice([0, 1, 2, 5]))
    em.w32(0x70039c, G)
    LO = obj(c, 0x40, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, stackmark=(2,), side=lambda emu, k: emu.calllog.append(('log2c', emu.arg32(1), cs(emu, emu.arg32(2)))))})
    MG = obj(c, 0x40, {0x20: pystub(c, 2, ret=LO, pop=8, this=True, side=lg('mg20', 0, 1))})
    em.w32(0x700390, MG)
    # [H + 0xae4] object table (49df60 lookup) is a heap object; 0x49e0d0 returns its name pointer
    ae4 = 0 if r.random() < 0.15 else rnd(c, 0x40)
    em.w32(H + 0xae4, ae4)
    # --- hooks (every direct callee)
    def h5da(emu, k):
        emu.calllog.append(('d860', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))
    hook_rec(c, 0x5da860, 2, ret=lambda emu, k: r.choice([0, 1, 1, 1, 0x101]), pop=8, this=True, side=h5da)
    hook_rec(c, 0x59fb50, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('b50'))

    def h43(emu, k):
        d = emu.reg('ecx')
        emu.calllog.append(('e920', bytes(emu.rbytes(emu.reg('edx'), 12)), bytes(emu.rbytes(emu.arg32(0), 12))))
        y = r.choice([0.0, 0.5, -0.5, 349.0, 350.0, -350.0, 351.0, 1000.0])
        x, z = r.choice([(0.0, 0.0), (0.5, 1.0), (1499.0, 0.0), (1500.0, 0.0), (0.0, 1500.0), (1501.0, 0.0), (0.0, -1499.0), (1000.0, 1118.0), (-2.0, 3.0)])
        emu.wbytes(d, pk(x) + pk(y) + pk(z))
    hook_rec(c, 0x43e920, 1, ret=r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=h43)
    hook_rec(c, 0x467060, 3, ret=lambda emu, k: r.getrandbits(32) | 1, pop=12, this=True, side=lambda emu, k: emu.calllog.append(('v060', emu.arg32(0), emu.arg32(1), emu.arg32(2))))
    hook_rec(c, 0x49e250, 1, ret=r.getrandbits(32), pop=4, this='mark', side=lambda emu, k: emu.calllog.append(('e250', cs(emu, emu.arg32(0)))))
    hook_rec(c, 0x49e260, 1, ret=r.getrandbits(32), pop=4, this='mark', side=lambda emu, k: emu.calllog.append(('e260', cs(emu, emu.arg32(0)))))
    objn = rnd(c, 0x40)
    em.w32(objn + 0x70, 0)

    def h49df(emu, k):
        emu.calllog.append(('df60', cs(emu, emu.arg32(0)), cs(emu, emu.arg32(1)), emu.reg('ecx')))
        st['found'] = 0 if r.random() < 0.2 else rnd(c, 0x40)
    st = {'found': 0}
    hook_rec(c, 0x49df60, 2, ret=lambda emu, k: st['found'], pop=8, this=True, stackmark=(0, 1), side=h49df)
    nm = em.alloc(0x40, 4)
    em.wbytes(nm, word(5, False))
    hook_rec(c, 0x49e0d0, 0, ret=lambda emu, k: r.choice([0, nm, nm]), pop=0, this=True, side=lg('e0d0'))

    def hms(emu, k):
        emu.calllog.append(('memset', emu.arg32(1), emu.arg32(2)))
        emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
    hook_rec(c, 0x634d10, 3, ret=r.getrandbits(32), pop=0, stackmark=(0,), side=hms)
    hook_rec(c, 0x59a5b0, 3, ret=r.getrandbits(32), pop=12, this=True, side=lambda emu, k: emu.calllog.append(('a5b0', emu.reg('ecx'), emu.arg32(0), emu.arg32(1), emu.arg32(2))))
    hook_rec(c, 0x598e10, 3, ret=r.getrandbits(32), pop=12, this=True, side=lambda emu, k: emu.calllog.append(('e10', emu.reg('ecx'), emu.arg32(0), emu.arg32(1), emu.arg32(2))))
    em.w32(0x6aed24, r.getrandbits(32))
    # --- arguments
    a0 = r.choice([0, 1, 5, 0x26, 0x27, 0x30, 0x3f])
    a1 = 0 if r.random() < 0.4 else em.alloc(0x40, 4)
    if a1:
        em.wbytes(a1, word(r.choice([0, 3, 9, 20]), False))
    a2 = r.choice([0, 1, 5])
    return [me, a0, a1, a2]


S(0x5a1c50, 'GUESS spawn effect for item index: resolves a model path, looks up a template and instantiates it', 'thiscall', 3, ret='eax', gen=g5a1c50, note='batch244041')
