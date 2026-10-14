"""specs_s38065.py - cascade s8 batch 38065: 0x6031e0. thiscall(stream) ret 4. this+1 -> header node of a packed tree (+1 parent, +5 left, +9 right, +0x19 value ptr; 0..6 random-shaped nodes, null
children), values with optional sub block (+0x24) and optional object with slot 0xc (+0x1c). The stream's slots (0x8, 0x2c, 0x30, 0x40, 0x1c, 0x10, 0x74, 0x48) are logging stubs (every call logged);
md5 init/update/final (0x6061f0/0x606940/0x606120) are hooked (update logs data pointer and length = the caller's entry EDI)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g6031e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lslot(name, nargs, retf=lambda: 0):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx') != 0) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=retf(), argbytes=4 * nargs)
        return e.stub_fn(name, h)
    slots = {0x08: lslot('s8', 1), 0x2c: lslot('s2c', 1), 0x30: lslot('s30', 1), 0x40: lslot('s40', 1),
             0x1c: lslot('s1c', 0, lambda: r.getrandbits(32)), 0x10: lslot('s10', 1, lambda: r.getrandbits(32)),
             0x74: lslot('s74', 1, lambda: r.getrandbits(32)), 0x48: lslot('s48', 2)}
    stream = obj(c, 0x80, slots)

    def init(em, res_):
        em.calllog.append(('md5init',))
        em.ret(eax=0, argbytes=0)

    def upd(em, res_):
        em.calllog.append(('md5upd', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)

    def fin(em, res_):
        em.calllog.append(('md5fin', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x6061f0, init)
    e.hook(0x606940, upd)
    e.hook(0x606120, fin)

    def value():
        v = e.alloc(0x30, 4)
        e.wbytes(v, r.randbytes(0x30))
        sub = 0
        if r.random() < 0.5:
            sub = e.alloc(0x30, 4)
            e.wbytes(sub, r.randbytes(0x30))
        e.w32(v + 0x24, sub)
        if r.random() < 0.5:
            e.w32(v + 0x1c, obj(c, 0x20, {0xc: lslot('o0c', 2)}))
        else:
            e.w32(v + 0x1c, 0)
        return v
    n = r.choice([0, 1, 2, 3, 4, 6, 3, 5])
    this = e.alloc(0x40, 4)
    e.wbytes(this, r.randbytes(0x40))
    head = e.alloc(0x20, 1)
    e.wbytes(head, r.randbytes(0x20))
    nodes = []

    def build(k):
        if k == 0:
            return 0
        nl = r.randrange(k)
        nd = e.alloc(0x20, 1)
        e.wbytes(nd, r.randbytes(0x20))
        e.wbytes(nd + 0x19, struct.pack('<I', value()))
        left = build(nl)
        right = build(k - 1 - nl)
        for off, ch in ((5, left), (9, right)):
            e.wbytes(nd + off, struct.pack('<I', ch))
            if ch:
                e.wbytes(ch + 1, struct.pack('<I', nd))
        return nd
    root = build(n)
    if root:
        lm = root
        while struct.unpack('<I', e.rbytes(lm + 5, 4))[0]:
            lm = struct.unpack('<I', e.rbytes(lm + 5, 4))[0]
        rm = root
        while struct.unpack('<I', e.rbytes(rm + 9, 4))[0]:
            rm = struct.unpack('<I', e.rbytes(rm + 9, 4))[0]
        e.wbytes(head + 1, struct.pack('<I', root))
        e.wbytes(root + 1, struct.pack('<I', head))
        e.wbytes(head + 5, struct.pack('<I', lm))
        e.wbytes(head + 9, struct.pack('<I', rm))
    else:
        e.wbytes(head + 1, struct.pack('<I', 0))
        e.wbytes(head + 5, struct.pack('<I', head))
        e.wbytes(head + 9, struct.pack('<I', head))
    e.wbytes(this + 1, struct.pack('<I', head))
    return [this, stream]


S(0x6031e0, 'GUESS serialize node map to stream + md5', 'thiscall', None, ret='eax', gen=_g6031e0, note='batch38065')
