"""specs_s213159.py - batch 213159: component setup by child names (sub-object slot-0 calls, effect record, float combine), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g5257a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def cstr(addr):
        out = bytearray()
        while True:
            b = bytes(e.rbytes(addr, 1))[0]
            if b == 0:
                break
            out.append(b)
            addr += 1
        return bytes(out)

    def cmp850(emu, k):
        a = cstr(emu.reg('ecx'))
        b = cstr(emu.reg('edx'))
        emu.calllog.append(('cmp', a, b))
        return 0 if a.lower() == b.lower() else 1
    hook_rec(c, 0x4cc850, 0, pop=0, this=True, ret=cmp850)

    def h516b60(emu, k):
        emu.calllog.append(('e516b60', emu.arg32(0), emu.arg32(1), emu.arg32(2)))
    hook_rec(c, 0x516b60, 3, pop=0xc, this=True, side=h516b60)
    hook_rec(c, 0x516f40, 1, pop=4, this=True, stackmark=(0,),
             side=lambda emu, k: emu.calllog.append(('e516f40', bytes(emu.rbytes(emu.arg32(0), 12)))))
    names = [bytes(e.rbytes(a, 16)).split(b'\0')[0] for a in range(0x6a0878, 0x6a0900, 0x10)]
    this = rnd(c, 0x1400)
    always_true = [False]
    # embedded sub-objects (vtable pointer at the start): slot 0
    offs = (0x7ad, 0x910, 0xa73, 0xbd6, 0xd39, 0xe6c, 0xf9f, 0x10d2)
    for off in offs:
        vt = e.alloc(8, 4)
        w32u(vt, pystub(c, 3, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if (always_true[0] or r.random() < 0.7) else 0)))
        w32u(this + off, vt)
    # child list
    root = rnd(c, 0x80)
    w32u(this + 0x88, root)
    kids = []
    plan = None
    if r.random() < 0.75:
        always_true[0] = True
        c1 = r.choice([2, 2, 4, 4, 1, 3, 0, 5])
        c2 = r.choice([2, 2, 4, 4, 1, 3, 0, 5])
        plan = [names[r.randrange(4)] for _ in range(c1)] + [names[4 + r.randrange(4)] for _ in range(c2)] \
            + [names[8]] * r.choice([0, 1, 2, 3]) + [b'Other'] * r.choice([0, 1])
        r.shuffle(plan)
    for i in range(len(plan) if plan is not None else r.choice([0, 1, 2, 3, 5, 8])):
        nd = rnd(c, 0x80)
        P = rnd(c, 0x20)
        t = r.random()
        if t < 0.1 and plan is None:
            w32u(nd + 0x54, 0)
        else:
            nm = e.alloc(32, 4)
            nbytes = plan[i] if plan is not None else r.choice(names + names + [b'Other', b'', b'FRONT'])
            if r.random() < 0.3:
                nbytes = nbytes.upper()
            e.wbytes(nm, nbytes + b'\0' * 8)
            w32u(P + 4, nm if r.random() > 0.05 else 0)
            w32u(nd + 0x54, P)
        kids.append(nd)
    for i, nd in enumerate(kids):
        w32u(nd + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
    w32u(root + 0x50, kids[0] if kids else 0)
    w32u(root + 4, r.choice([0, 0x6a0904]))
    # floats used by the combine step
    for off in (0x7d1, 0xa97, 0xd5d, 0xfc3, 0x7c9, 0x92c):
        wf(this + off, r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.5, r.uniform(-5, 5), 100.0]))
    # logger
    def mh(em, res_):
        em.calllog.append(('mlog', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)
    return [this, rb()]


S(0x5257a0, 'component_setup', 'thiscall', None, ret='al', gen=g5257a0, stack_arg_bytes=12)
