"""specs_s46004.py - cascade t7 batch 46004: 0x4d0100 pool allocator release-by-key. A consistent pool is built (nodes linked at this+0x8220, blocks with
signed sizes, prev-size fields, size 0 terminator); 0x41e290, 0x634273, 0x4d0c70, IAT free 0x6762ec and the vtable slots are recorders; the assert hook is always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g4d0100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    keys = [0x1111, 0x2222, 0x3333]
    key = r.choice(keys)
    nn = r.choice([0, 1, 2, 2, 3, 4])
    nodes = []
    for _ in range(nn):
        nb = r.choice([1, 1, 2, 3, 4, 5])
        sizes = []
        for _ in range(nb):
            m = r.choice([0x20, 0x30, 0x40, 0x80, 0x100, 0x100 + 0x10 * r.randrange(0, 16)])
            sizes.append(-m if r.random() < 0.6 else m)
        total = 0x10 + sum(0x10 + abs(s) for s in sizes) + 0x10 + 0x10
        mem = rnd(c, total + 0x10) + 0x10
        blocks = []
        p = mem + 0x10
        prev = 0
        for s in sizes:
            e.w32(p + 4, r.choice(keys) if r.random() > 0.3 else key)
            e.w32(p + 8, s & 0xffffffff)
            e.w32(p + 0xc, prev & 0xffffffff)
            blocks.append(p)
            prev = s
            p = p + 0x10 + abs(s)
        e.w32(p + 4, 0)
        e.w32(p + 8, 0)
        e.w32(p + 0xc, prev & 0xffffffff)
        # mutate consistency now and then (error paths) or mark a block as a big allocation
        if False:
            pass
        if r.random() < 0.06:
            b = r.choice(blocks)
            e.w32(b + 0xc, 0xffffffff)
        if r.random() < 0.05:
            e.w32(p + 0xc, r.getrandbits(32))
        nodes.append(mem)
    for i, m in enumerate(nodes):
        e.w32(m, nodes[i - 1] if i > 0 else 0)
        e.w32(m + 4, nodes[i + 1] if i + 1 < len(nodes) else 0)

    # hooks
    hook_rec(c, 0x41e290, 1, pop=0, ret=rnd(c, 4 * max(nn, 1) + 16))
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4d0c70, 2, this=True)
    e.w32(0x6762ec, pystub(c, 1, pop=0))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    errobj = obj(c, 0x40, {0x2c: pystub(c, 2, pop=0)})
    g = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=errobj)})
    e.w32(0x700390, g)

    me = rnd(c, 0x12200)
    unit = r.choice([0x10, 0x40, 0x100, 0x400])
    e.w32(me + 0x8217, unit)
    e.w32(me + 0x8220, nodes[0] if nodes else 0)
    e.w32(me + 0x8224, nn)
    far = False
    if nodes:
        base = nodes[0]
        k = r.random()
        if k < 0.2:
            e0 = 0xffffffff
        elif k < 0.3:
            e0 = r.choice(nodes)
        elif k < 0.38:
            e0 = (base - unit * 0x2000 + r.randrange(0, 0x100)) & 0xffffffff
            far = True
        elif k < 0.85:
            e0 = base - r.randrange(0, 0x200)
        else:
            e0 = (base - 0x3000000) & 0xffffffff
    else:
        e0 = 0xffffffff
    e.wbytes(me + 0x20f, e0.to_bytes(4, 'little'))
    e.wbytes(me + 0x20b, r.getrandbits(32).to_bytes(4, 'little'))
    # page counters near the pool: make some low 16 bits zero after the subtraction
    nent = 0x2000 if far else 0x600
    arr = bytearray()
    for i in range(nent):
        if r.random() < (0.98 if far else 0.7):
            arr += ((unit + (r.getrandbits(16) << 16)) & 0xffffffff).to_bytes(4, 'little')
        else:
            arr += r.getrandbits(32).to_bytes(4, 'little')
    e.wbytes(me + 0x217, bytes(arr))
    cls = r.choice([0xb, 0xb, 0, 3, 7, 10])
    e.w32(me + 0x1c8, cls)
    bks = [rnd(c, 0x40) for _ in range(6)]
    for b in bks:
        e.wbytes(b + 0x11, (r.choice([0, 0, rnd(c, 0x20)])).to_bytes(4, 'little'))
    e.w32(me + 0x1c4, r.choice([0, 0, 1, 2, 3]))
    for i in range(4):
        e.w32(me + 0x34 + 4 * i, bks[i])
    e.w32(me + 0x12130, r.randrange(0, 4))
    for i in range(8):
        e.w32(me + 0x11530 + 4 * i, bks[i % 6])
    e.w32(me + 0xd628, r.randrange(1, 12))
    for i in range(24):
        e.w32(me + 0xc628 + 4 * i, rnd(c, 0x20))

    # embedded sub-objects (vtable pointer stored in the object itself)
    bk_ret = [r.choice([0, 0, bks[4], bks[5]]) for _ in range(8)]
    vt1 = c.emu.alloc(0x40, 4)
    e.w32(vt1 + 0, pystub(c, 1, this=True))
    e.w32(vt1 + 8, pystub(c, 2, this=True, ret=lambda em, k: bk_ret[min(k, 7)]))
    e.w32(me + 0x1cc, vt1)
    vt2 = c.emu.alloc(0x40, 4)
    e.w32(vt2 + 0, pystub(c, 1, this=True))
    vt4r = [rnd(c, 0x20) for _ in range(8)]
    e.w32(vt2 + 4, pystub(c, 1, this=True, ret=lambda em, k: vt4r[min(k, 7)]))
    rbr = [r.choice([0, 1, r.getrandbits(32)]) for _ in range(8)]
    e.w32(vt2 + 8, pystub(c, 2, this=True, ret=lambda em, k: rbr[min(k, 7)]))
    e.wbytes(me + 0x1ea, vt2.to_bytes(4, 'little'))
    return [me, key]


S(0x4d0100, 'GUESS pool allocator release blocks by key', 'thiscall', None, ret=None, gen=g4d0100, note='batch46004')
