"""specs_s890.py - area 50, batch 890: 0x58a8d0 (GUESS name Collect58a8d0), FASTCALL (ECX = this, EDX = output array), no stack
args, returns this (eax). Stand-ins (hooked through the object's vtable, logged): slot +0x48 (first call writes the item count,
later calls write a dword), +0x40 (writes a handle), +0x50 and +0x6c (write 12 bytes). The manager (g+0x9b) maps a handle to a value
through its slot +0x58. The output array (heap) gets the count and the 48-byte records; its heap bytes are compared."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    cnt = r.randint(0, 3)
    hs = [r.getrandbits(32) for _ in range(3)]
    vals = {h: r.getrandbits(32) for h in hs}
    blocks = {}
    calls48 = [0]

    def h48(e, rr):
        k = calls48[0]
        calls48[0] += 1
        e.w32(e.arg32(0), cnt if k == 0 else (k * 0x9e3779b9) & 0xffffffff)
        e.calllog.append(('s.48', k, e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=4)

    hidx = [0]

    def h40(e, rr):
        k = hidx[0] % len(hs)
        hidx[0] += 1
        e.w32(e.arg32(0), hs[k])
        e.calllog.append(('s.40', k))
        e.ret(eax=0, argbytes=4)

    blk = [0]

    def blockw(tag):
        def h(e, rr):
            k = blk[0]
            blk[0] += 1
            data = bytes((k * 37 + i * 11 + len(tag)) & 0xff for i in range(12))
            e.wbytes(e.arg32(0), data)
            e.calllog.append(('s.' + tag, k, data))
            e.ret(eax=0, argbytes=4)
        return h

    self_vt = e.fake_vtable('self', 0x100, {0x40: h40, 0x48: h48, 0x50: blockw('50'), 0x6c: blockw('6c')})
    self = rnd(c, 0x200)
    e.w32(self, self_vt)

    def m58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k in vals))
        e.ret(eax=vals.get(k, 0), argbytes=4)

    mgr_vt = e.fake_vtable('mgr', 0x100, {0x58: m58})
    mgr = rnd(c, 0x1000)
    e.w32(mgr, mgr_vt)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    out = rnd(c, 0x400)
    e.w32(out, r.randint(0, 2))
    return [self, out]


S(0x58a8d0, 'Collect58a8d0 (GUESS name)', 'fastcall', None, ret='eax', gen=_gen, note='area50 batch890')
