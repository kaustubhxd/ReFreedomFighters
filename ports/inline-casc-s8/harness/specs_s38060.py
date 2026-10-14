"""specs_s38060.py - cascade s8 batch 38060. Parent object (this slot 0x84) with an embedded list object at +0xcb (unaligned vtable pointer; slot 0x14 returns 0 / non-zero per call from a per-case sequence so
the 'empty twice', 'empty then filled', 'filled' cases all run), slots 0x30c / 0x114 and the +0x6f object's slot 0x254; this[0x44] page object (slots 0x2dc, 0x130, +4 name pointer equal to the image string
at 0x6a6644 half of the time), this[0xf8] (null 30%), this[0x94] page (flag byte +0x1041, null 15%; the unaligned dword at +0x1329b is in the compare), this[0xfc] (null 25%); global table at [0x7003b8]
with the four hot-key dwords at +0x2c3d (zero 25% each); engine table slots 0x114 / 0xb4 and the config object (null 20%). Return is the low byte (AL)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g562e90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seq = [r.choice([0, 0, 1, 2]) for _ in range(3)]
    cnt = [0]

    def emb14(em, res_):
        k = min(cnt[0], 2)
        cnt[0] += 1
        em.calllog.append(('emb14', em.reg('ecx')))
        em.ret(eax=seq[k] if k < 2 else r.choice([0, 1]), argbytes=0)
    emvt = e.alloc(0x40, 4)
    e.w32(emvt + 0x14, e.stub_fn('emb14', emb14))
    q = obj(c, 0x20, {0x254: pystub(c, 0, this=True)})
    r25c = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: 0)})
    sobj = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})
    rr = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: sobj if r.random() < 0.8 else 0)})
    par = obj(c, 0x200, {0x30c: pystub(c, 1, this=True), 0x114: pystub(c, 1, this=True),
                         0x25c: pystub(c, 2, this=True, ret=lambda em, k: rr if r.random() < 0.8 else 0)})
    e.wbytes(par + 0xcb, struct.pack('<I', emvt))
    e.wbytes(par + 0x6f, struct.pack('<I', q))
    nm = e.alloc(16, 1)
    cst = bytes(e.rbytes(0x6a6644, 12)).split(b'\0')[0] + b'\0'
    e.wbytes(nm, cst if r.random() < 0.5 else b'other\0')
    o44 = obj(c, 0x40, {0x2dc: pystub(c, 2, this=True), 0x130: pystub(c, 3, this=True)})
    e.w32(o44 + 4, nm if r.random() > 0.15 else 0)
    page = e.alloc(0x13400, 4)
    e.wbytes(page, r.randbytes(0x13400))
    e.wbytes(page + 0x1041, bytes([r.choice([0, 1, 1, 2])]))
    me = obj(c, 0x200, {0x84: pystub(c, 0, this=True, ret=par), 0x68: pystub(c, 2, this=True), 0xc4: pystub(c, 1, this=True)})
    e.w32(me + 0x44, o44)
    e.w32(me + 0xf8, obj(c, 0x20, {0x214: pystub(c, 1, this=True)}) if r.random() > 0.3 else 0)
    e.w32(me + 0xf0, r.getrandbits(32))
    e.w32(me + 0x94, page if r.random() > 0.15 else 0)
    e.w32(me + 0xfc, obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}) if r.random() > 0.25 else 0)
    e.wbytes(me + 0x88, bytes([r.getrandbits(8)]))
    e.w32(me + 0xdc, r.getrandbits(32))
    glob = e.alloc(0x2c60, 4)
    e.wbytes(glob, r.randbytes(0x2c60))
    for k in range(4):
        if r.random() < 0.25:
            e.wbytes(glob + 0x2c3d + 4 * k, bytes(4))
    e.w32(0x7003b8, glob)
    so = sysobj(c, {}, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: (r.getrandbits(16) << 16) | r.getrandbits(16)),
                                    0xb4: pystub(c, 1, this=True)})
    cfg = obj(c, 0x20, {0x138: pystub(c, 1, this=True)})
    e.wbytes(so + 0x1a9f, struct.pack('<I', cfg if r.random() > 0.2 else 0))
    return [me, r.getrandbits(32), r.choice([0, 1, 0x101, 0x100, r.getrandbits(32)])]


S(0x562e90, 'GUESS leave menu page', 'thiscall', None, ret='al', gen=_g562e90, note='batch38060')
