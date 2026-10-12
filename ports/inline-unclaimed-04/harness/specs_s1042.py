"""specs_s1042.py - unclaimed-04 batch 42 (docs/20-unclaimed-04.md): 0x5f3ff0 (thiscall, one stack argument a, ret 4).
The tree object is at this+0x96 (the batch 40 tree: root at +0x118, key word at +0xd, children at +5/+9, value dword at +0xf;
the value is a pointer to a 0x20-byte object whose +8 is read). 0x5fa630 is hooked by address (recording, returns X). X's
slot 0x48 (three arguments, recording) returns Y or 0; Y's slot 0x48 (two arguments, recording) returns 0. Results are random per case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def h5fa630(em, r):
        em.calllog.append(('5fa630', 0, 0, ()))
        em.ret(eax=getattr(em, 'x_obj', 0), argbytes=0)

    c.emu.hook(0x5fa630, h5fa630)


def _args(c):
    this = _rnd(c, 0x200)
    tree = _rnd(c, 0x200)
    c.emu.w32(this + 0x96, tree)
    root = _rnd(c, 0x20)
    c.emu.w32(tree + 0x118, root)
    n = c.rng.randrange(0, 5)
    nodes = []
    for i in range(n):
        nd = _rnd(c, 0x20)
        B = _rnd(c, 0x20)
        c.emu.w32(B + 8, c.rng.getrandbits(32))
        c.emu.wbytes(nd + 0xd, bytes([c.rng.randrange(0, 8), c.rng.randrange(0, 2)]))
        c.emu.w32(nd + 0xf, B)
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        later = nodes[i + 1:] + [0]
        c.emu.w32(nd + 5, c.rng.choice(later))
        c.emu.w32(nd + 9, c.rng.choice(later))
    c.emu.w32(root + 1, nodes[0] if nodes else 0)

    y_ret_obj = _rnd(c, 0x20)

    def h48_y(em, r):
        em.calllog.append(('Y.48', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    Y_vt = c.emu.fake_vtable('Y', 0x48 // 4 + 1, {0x48: h48_y})
    c.emu.w32(y_ret_obj, Y_vt)
    y_for_x = y_ret_obj if c.rng.random() < 0.7 else 0

    def h48_x(em, r):
        em.calllog.append(('X.48', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=y_for_x, argbytes=12)

    X_vt = c.emu.fake_vtable('X', 0x48 // 4 + 1, {0x48: h48_x})
    x_obj = _rnd(c, 0x20)
    c.emu.w32(x_obj, X_vt)
    c.emu.x_obj = x_obj
    return [this, c.rng.randrange(0, 9) | (c.rng.getrandbits(16) << 16)]


S(0x5f3ff0, 'unknown::tree_then_vt48_chain (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args, setup=_setup,
  note='unclaimed-04 batch 42; 0x5fa630 hooked by address (GUESS); vt slots 0x48 recording stubs')
