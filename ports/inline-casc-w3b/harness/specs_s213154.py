"""specs_s213154.py - batch 213154: bounding vectors over a node list with real vector helpers, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g443080(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', v))

    def fv():
        return r.choice([0.0, 1.0, -1.0, 0.5, 2.0, 3.25, r.uniform(-4, 4), r.uniform(-4, 4)])
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    flagsets = [0x800000, 0x200002, 0x800002, 0, 0x100000, 0x800000]

    def mk_prop():
        Y = rnd(c, 0x60)
        w32u(Y + 0x23, r.choice(flagsets))
        return Y

    def lg64(emu, k):
        emu.calllog.append(('i64', bytes(emu.rbytes(emu.arg32(0), 0x30)), bytes(emu.rbytes(emu.arg32(1), 12)), bytes(emu.rbytes(emu.arg32(2), 12)), emu.arg32(3)))

    def mk_node(depth=1):
        n = rnd(c, 0x100)
        for off in list(range(0x24, 0x50, 4)) + [0x30, 0x34, 0x38]:
            wf(n + off, fv())
        w32u(n + 0x3c, r.choice([0, 0x80000, 0x80000, 0x1, 0x80001]))
        # optional child chain (used by 0x4db600 helpers)
        w32u(n + 0x50, mk_node(depth - 1) if depth > 0 and r.random() < 0.3 else 0)
        if r.random() < 0.75:
            it = obj(c, 0x40, {0x64: pystub(c, 4, this=True, stackmark=(0, 1, 2), side=lg64)}, nslots=0x30)
            w32u(it + 0xc, mk_prop())
            w32u(n + 0x54, it)
        else:
            w32u(n + 0x54, 0)
        return n
    nodes = [mk_node() for _ in range(r.choice([1, 1, 2, 3, 4]))]
    st = {'i': 1}

    def nxt(emu, k):
        i = st['i']
        st['i'] += 1
        emu.w32(emu.arg32(0), nodes[i] if i < len(nodes) else 0)

    def lg94(emu, k):
        emu.calllog.append(('t94', bytes(emu.rbytes(emu.arg32(0), 0x30)), bytes(emu.rbytes(emu.arg32(1), 12))))
    this = obj(c, 0x40, {0x94: pystub(c, 2, this=True, stackmark=(0, 1), side=lg94),
                        0x50: pystub(c, 1, this=True, stackmark=(0,), side=nxt)}, nslots=0x60)
    w32u(this + 8, nodes[0])
    a = rnd(c, 0x20)
    for off in (0, 4, 8):
        wf(a + off, fv())
    return [this, a]


S(0x443080, 'bounds_accumulate', 'thiscall', None, ret='st0', gen=g443080, stack_arg_bytes=12)
