"""specs_s213166.py - batch 213166: slot bookkeeping rebuild (jump table on a kind byte, id lists moved between sub-lists, clamped ranges), every sub-object method hooked, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g568350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    ids = [3, 5, 6, 7, 8, 0xb, 4, 0xa, 0xd, 0xc, 0xe, 0x10, 0xf]
    pick_id = lambda: r.choice(ids + [0, 0x11])

    # ---- engine
    names = {0x681320: rb(), 0x6a7374: rb(), 0x6a738c: rb()}

    def x88(emu, k):
        nm, out = emu.arg32(0), emu.arg32(1)
        emu.w32(out, names.get(nm, 0))
        emu.calllog.append(('x88', nm))
    X = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=x88)}, nslots=0x60)
    T = obj(c, 0x20, {0x138: pystub(c, 0, this=True, ret=X),
                      0x58: pystub(c, 1, this=True, ret=lambda emu, k: rb(), side=lambda emu, k: emu.calllog.append(('t58', emu.arg32(0))))}, nslots=0x160)
    eng = rnd(c, 0x200)
    w32u(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    # ---- this and its sub-objects
    o94 = rnd(c, 0x100)
    kind = r.choice([0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x31, 0x39, 0xb0, 0x32, 0x35, 0x38])
    e.wbytes(o94 + 0x4a, bytes([kind]))
    this = obj(c, 0x500, {0x64: pystub(c, 1, this=True)}, nslots=0x40)
    w32u(this + 0x94, o94 if r.random() < 0.93 else 0)
    base180 = this + 0x180
    base1d4 = this + 0x1d4
    # pairs and the table of entries
    for a in (0x3f2, 0x3fa, 0x402, 0x40a, 0x412, 0x41a, 0x422, 0x42a):
        w32u(this + a, r.choice(ids + [0, rb()]))
    for i in range(0x11):
        w32u(this + 0x326 + i * 12, rb())

    # ---- nodes
    def mk_node():
        s354 = rb() >> r.choice([0, 8, 20])
        ob = obj(c, 0x20, {0x354: pystub(c, 0, this=True, ret=lambda emu, k, v=s354: v)}, nslots=0x360)
        nd = rnd(c, 0x40)
        w32u(nd, ob)
        w32u(nd + 4, rb() >> r.choice([0, 8, 20]))
        w32u(nd + 0xc, rb() >> r.choice([4, 8, 20]))
        w32u(nd + 0x10, rb())
        e.wbytes(nd + 0x14, bytes([r.choice([0, 1, 1, 0x80])]))
        return {'addr': nd, 's354': s354}
    maps = {base180: {}, base1d4: {}}
    for mp in maps.values():
        for i in ids + [0x11]:
            if r.random() < 0.7:
                mp[i] = mk_node()
    allnodes = {n['addr']: n for mp in maps.values() for n in mp.values()}
    node_list = list(allnodes.values())

    def h5af130(emu, k):
        idv = emu.arg32(0)
        emu.calllog.append(('n130', emu.reg('ecx'), idv))
        n = maps.get(emu.reg('ecx'), {}).get(idv)
        return n['addr'] if n else 0
    hook_rec(c, 0x5af130, 1, pop=4, this=False, ret=h5af130)

    hook_rec(c, 0x5aee60, 1, pop=4, this=True)

    state = {'a': 0, 'c': 0}

    def fix_equal(emu, ids_ptr, deltas_ptr):
        # make node[4] + delta land on / around the limit for the nodes of the second range report
        for i in range(2):
            idv = struct.unpack('<I', bytes(emu.rbytes(ids_ptr + 4 * i, 4)))[0]
            dv = struct.unpack('<I', bytes(emu.rbytes(deltas_ptr + 4 * i, 4)))[0]
            n = maps[base1d4].get(idv)
            if n is not None and r.random() < 0.5:
                base = struct.unpack('<I', bytes(emu.rbytes(n['addr'] + 0xc, 4)))[0]
                lim = (n['s354'] + base) & 0xffffffff
                emu.w32(n['addr'] + 4, (lim - dv + r.choice([0, 0, 1, -1])) & 0xffffffff)

    def out2(key):
        def side(emu, k):
            first = state[key] == 0
            state[key] += 1
            a0 = r.choice([0, 0, 1, rb()]) if first else pick_id()
            a1 = rb() >> r.choice([0, 8, 20])
            emu.w32(emu.arg32(0), a0)
            emu.w32(emu.arg32(1), a1)
            emu.calllog.append((key, a0, a1))
            if key == 'c' and not first:
                fix_equal(emu, emu.arg32(0) - 4, emu.arg32(1) - 4)
        return side
    hook_rec(c, 0x5b04a0, 2, pop=8, this=True, stackmark=(0, 1), side=out2('a'))
    hook_rec(c, 0x5b04c0, 2, pop=8, this=True, stackmark=(0, 1), side=out2('c'))
    hook_rec(c, 0x5adda0, 0, pop=0, this=True, ret=lambda emu, k: (rb() & ~0xff) | r.choice([0, 1, 0x80]))
    hook_rec(c, 0x5aef80, 1, pop=4, this=True, ret=lambda emu, k: rb())
    hook_rec(c, 0x5b07d0, 2, pop=8, this=True)
    hook_rec(c, 0x5b07f0, 2, pop=8, this=True)
    hook_rec(c, 0x567930, 1, pop=4, this=True)
    cont_ids = set(r.sample(ids, r.randrange(0, len(ids) + 1)))
    hook_rec(c, 0x5af230, 1, pop=4, this=True, ret=lambda emu, k: (rb() & ~1) | (1 if emu.arg32(0) in cont_ids else 0) if r.random() < 0.9 else 0)
    hook_rec(c, 0x5aefc0, 1, pop=4, this=True, ret=lambda emu, k: rb())
    hook_rec(c, 0x5aedf0, 1, pop=4, this=True)

    def s5afc10(emu, k):
        d = emu.reg('ecx')
        emu.wbytes(d, bytes(r.getrandbits(8) for _ in range(0x24)))
        emu.calllog.append(('c10', bytes(emu.rbytes(d, 0x24))))
    hook_rec(c, 0x5afc10, 0, pop=0, this=False, side=s5afc10)

    def s5afce0(emu, k):
        emu.calllog.append(('ce0', bytes(emu.rbytes(emu.reg('ecx'), 0x24))))
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(20)))
    hook_rec(c, 0x5afce0, 1, pop=4, this=False, stackmark=(0,), side=s5afce0)

    def s5af2a0(emu, k):
        d = emu.reg('ecx')
        emu.calllog.append(('2a0', bytes(emu.rbytes(d, 20)), emu.arg32(0), emu.arg32(1)))
        emu.w32(d + 4 * (emu.arg32(0) % 5), rb())
    hook_rec(c, 0x5af2a0, 2, pop=8, this=False, stackmark=(), side=s5af2a0)
    hook_rec(c, 0x5b04e0, 5, pop=0x14, this=True)
    hook_rec(c, 0x5af260, 1, pop=4, this=True)
    hook_rec(c, 0x5aef10, 0, pop=0, this=True)
    cnt = r.choice([0, 1, 2, 3, len(node_list)]) if node_list else 0
    cnt = min(cnt, len(node_list))
    hook_rec(c, 0x4cc1d0, 0, pop=0, this=True, ret=lambda emu, k: cnt)
    hook_rec(c, 0x5af0d0, 1, pop=4, this=True, ret=lambda emu, k: node_list[emu.arg32(0) % len(node_list)]['addr'])
    hook_rec(c, 0x5aee20, 2, pop=8, this=True)
    hook_rec(c, 0x569260, 0, pop=0, this=True)
    return [this]


S(0x568350, 'slot_rebuild', 'thiscall', None, ret=None, gen=g568350)
