"""specs_s213147.py - batch 213147: screen set-up (widget lookups, sibling chain with table lookups, name-driven table entry), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g562750(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def pair_log(emu, k):
        emu.calllog.append(('pair', bytes(emu.rbytes(emu.reg('ecx'), 8))))
    hook_rec(c, 0x48aad0, 0, pop=0, this='mark', ret=lambda emu, k: rb(), side=pair_log)
    cands = []   # filled below: widget candidates for the 0x6a6514 lookups

    def pick():
        return r.choice(cands) if cands else 0

    def mk_widget():
        w = [None]

        def w70(emu, k):
            emu.calllog.append(('w70', emu.reg('ecx'), bytes(emu.rbytes(emu.arg32(0), 12))))
        slots = {0x70: pystub(c, 1, this=True, stackmark=(0,), side=w70),
                 0x25c: pystub(c, 2, this=True, ret=lambda emu, k: pick())}
        return slots
    # sibling chains
    chains = []
    for ci in range(2):
        n = r.choice([0, 1, 2, 3, 5, 8, 9, 10])
        nodes = []
        for i in range(n + 1):
            nodes.append(None)
        # build from the tail so each node knows its next
        nxt = [0] * (n + 1)
        objs = []
        for i in range(n + 1):
            objs.append([None, None])
        # create objects first with a mutable cell for next
        cells = [{'next': 0} for _ in range(n + 1)]
        ws = []
        for i in range(n + 1):
            cell = cells[i]
            slots = mk_widget()
            slots[0x318] = pystub(c, 1, this=True, ret=lambda emu, k, cell=cell: cell['next'])
            ws.append(obj(c, 0x40, slots, nslots=0x140))
        for i in range(n + 1):
            if i < n:
                cells[i]['next'] = ws[i + 1]
            else:
                cells[i]['next'] = r.choice([0, 0, ws[0], ws[0]])
        chains.append(ws[0])
    cands.extend([chains[0], chains[1], 0, 0])
    w54 = obj(c, 0x40, mk_widget(), nslots=0x140) if r.random() < 0.8 else 0
    A = obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=lambda emu, k: (w54 if emu.arg32(0) == 0x6a650c else pick()))}, nslots=0x140)
    E = rnd(c, 0x100)
    w32u(E + 0x73, r.choice([0x1c0, 0x1c1, 0x1c3, 0x1bf, 0x300, 0x3c, 0x3b, 0, 0x258, 0x2d0, r.randint(0, 3000), r.randint(0, 100)]))
    w32u(E + 0x6f, r.choice([0x280, 0x281, 0x27f, 0x400, 0x320, 0, r.randint(0, 3000), r.randint(0, 100)]))
    # table T
    def q_out(emu, k):
        emu.calllog.append(('r88', emu.arg32(0)))
        emu.wbytes(emu.arg32(1), struct.pack('<I', rb()))
    R = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=q_out)}, nslots=0x40)
    T = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, ret=lambda emu, k: rb()),
                      0x58: pystub(c, 1, this=True, ret=lambda emu, k: rb()),
                      0x138: pystub(c, 0, this=True, ret=lambda emu, k: R)}, nslots=0x60)
    w32u(E + 0x9b, T)
    e.w32(0x70039c, E)
    def mh(em, res_):
        em.calllog.append(('mlog', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    # this[0x94] source object
    G7 = rnd(c, 0x2c40)
    S94 = rnd(c, 0x1100)
    e.wbytes(S94 + 0x103f, bytes([r.choice([0, 1, 1, 1, 0xff])]))
    w32u(G7 + 0x2c15, S94 if r.random() < 0.9 else 0)
    e.w32(0x7003b8, G7)
    # name for this.0x84()
    name = r.choice([b'', b'ab1', b'x2', b'q3', b'z4', b'w5', b'v0', b'a\xb1', b'a\x01', b'\xff', b'1', b'2', b'3', b'4', b'5'])
    namep = e.alloc(16, 4)
    e.wbytes(namep, name + b'\0' * 8)
    # widgets C for this.0x84()->0x25c(0x6a6524)
    Cw = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda emu, k: rb())}, nslots=0x140) if r.random() < 0.8 else 0
    Bo = obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=lambda emu, k: Cw)}, nslots=0x140)
    w32u(Bo + 4, namep if r.random() < 0.7 else 0)
    # the default name string lives in the image: vary it so its start and length matter
    e.wbytes(0x67c8e8, r.choice([b'<NONAME>\0', b'2\0', b'41\0', b'\0', b'x3\0', b'44\0']))
    this = obj(c, 0x300, {0xbc: pystub(c, 0, this=True), 0x84: pystub(c, 0, this=True, ret=Bo)}, nslots=0x80)
    w32u(this + 0x44, A)
    w32u(this + 0x5c, r.choice([0, 0, chains[0], chains[1]]))
    w32u(this + 0xd8, r.choice([0, 0, 1, 3, 6, 7, 8, 9]))
    return [this]


S(0x562750, 'screen_setup', 'thiscall', None, ret=None, gen=g562750)
