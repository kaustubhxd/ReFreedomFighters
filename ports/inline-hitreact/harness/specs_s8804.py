"""specs_s8804.py - hitreact batch 8804: ZProjectile::ShotImpact (0x4ba7f0).
Patched to recording stubs: GetMaterialDesc 0x4ba180, GetOwnerRoom 0x4db3b0, the sound placement 0x43ebb0, the decal 0x45bab0
and the COLI hit-triangle normal 0x45bfd0 (fills a fixed normal). Exe code in both builds: createmat 0x4de040, vneg 0x4e09b0 /
0x4e09e0, COLI::COLI 0x4e1b60, vsetlen 0x4e0d80, 0x43e8e0, MYSTR 0x4cc1d0 / 0x4cbec0. Every virtual call is a stub that
records its scalar args and the contents of its pointer args (stack addresses are never recorded); the object transforms
(slots 0x84 / 0x88 / 0x8c / 0x90, room 0x8c) add a per-case vector so the data flow is checked. The SHitInfo +0x10 word is
recorded only when +8 (the weapon) is non-zero: on the other path the exe leaves stack garbage there."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from dkit import patch_jmp
from hkit import rec_stub, fvec


def _map_stub(c, mapping):
    """thiscall (handle), ret 4: returns mapping[handle] or 0; counts calls."""
    cnt = c.emu.alloc(4, 4)
    code = b'\x8b\x44\x24\x04'                      # mov eax,[esp+4]
    for h, v in mapping.items():
        code += b'\x3d' + struct.pack('<I', h & 0xffffffff) + b'\x75\x07'   # cmp eax,h; jne +7
        code += b'\xb8' + struct.pack('<I', v) + b'\xeb' + bytes([0])         # mov eax,v; jmp +0 (patched below)
    # simpler: rebuild with explicit jumps to the end
    parts = []
    for h, v in mapping.items():
        parts.append((h & 0xffffffff, v))
    code = b'\xff\x05' + struct.pack('<I', cnt) + b'\x8b\x44\x24\x04'
    tail = b'\x31\xc0\xc2\x04\x00'                   # xor eax,eax; ret 4
    blocks = []
    for h, v in parts:
        blocks.append(b'\x3d' + struct.pack('<I', h) + b'\x75\x08' + b'\xb8' + struct.pack('<I', v) + b'\xc2\x04\x00')
    code += b''.join(blocks) + tail
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _handle_stub(c):
    """thiscall (x), ret 4: returns x ^ 0x55aa0000; counts calls."""
    cnt = c.emu.alloc(4, 4)
    code = b'\xff\x05' + struct.pack('<I', cnt) + b'\x8b\x44\x24\x04\x35' + struct.pack('<I', 0x55aa0000) + b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _name_stub(c, ms):
    cnt = c.emu.alloc(4, 4)
    code = b'\x8b\x44\x24\x04\x8d\x50\x04\x89\x10\xff\x05' + struct.pack('<I', cnt) + b'\xb8' + struct.pack('<I', ms) + b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


V3 = [(0, 'd'), (4, 'd'), (8, 'd')]


def _gen(c):
    r = c.rng
    emu = c.emu
    fv = lambda lo=-500, hi=500: r.choice((r.uniform(lo, hi), 0.0, fedge(c)))
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    # handles
    H_HIT, H_DECAL, H_FX, H_FX2, H_W, H_SH = 0x101, 0x102, 0x103, 0x104, 0x105, 0x106
    pick = lambda h: h if r.random() < 0.8 else 0x999
    # objects
    geom = rnd(c, 0x80)
    emu.w16(geom + 0x5a, r.choice((0, 1)))
    addv = fvec(c, [r.uniform(-50, 50) for _ in range(3)])
    nrm_src = fvec(c, [fv(-1, 1) for _ in range(3)])
    hitpt = fvec(c, [fv() for _ in range(3)])
    hit = obj(c, 0x80, {
        0x1e0: rec_stub(c, 1, ret=r.choice((0, 1, 0x100, 0xffffff01))),
        0x88: rec_stub(c, 1, ptrs={0: V3}, adds={0: (addv, 3)}),
        0x90: rec_stub(c, 1, ptrs={0: V3}, adds={0: (addv, 3)}),
        0x8c: rec_stub(c, 1, ptrs={0: V3 + [(0xc, 'd'), (0x10, 'd'), (0x14, 'd'), (0x6c, 'b')]}, adds={0: (addv, 3)}),
        0x178: rec_stub(c, 2, ptrs={0: V3 + [(0xc, 'd'), (0x10, 'd'), (0x14, 'd')]}, fills={0: (hitpt, 3, 0x28)},
                        ret=r.choice((0, 1, 0x100))),
        0x84: rec_stub(c, 1, ptrs={0: V3}, adds={0: (addv, 3)}),
    })
    emu.w32(hit + 8, geom)
    room = obj(c, 0x100, {0x8c: rec_stub(c, 1, ptrs={0: V3}, adds={0: (addv, 3)}),
                          0x94: rec_stub(c, 2, ptrs={0: [(4 * i, 'd') for i in range(9)], 1: V3})})
    fxs = lambda: obj(c, 0x200, {0x1bc: rec_stub(c, 7, ptrs={1: [(4 * i, 'd') for i in range(9)], 2: V3})})
    fx, fx2 = fxs(), fxs()
    decal = rnd(c, 0x40)
    tmpl = rnd(c, 0x40)
    w = obj(c, 0x300, {0x2e8: rec_stub(c, 0, ret=tmpl)})
    sh = obj(c, 0x200, {0x128: rec_stub(c, 3)})
    own = obj(c, 0x200, {0x130: rec_stub(c, 3, ptrs={2: [(0, 'd'), (4, 'd'), (8, 'd'), (0xc, 'd'), (0x14, 'd')]}, cond=(2, 8, [0x10])),
                         0x128: rec_stub(c, 3, ptrs={1: [(4 * i, 'd') for i in range(10)]})})
    sobj = rnd(c, 0x80)
    mapping = {H_HIT: hit, H_DECAL: decal, H_FX: fx, H_FX2: fx2, H_W: w, H_SH: sh}
    if r.random() < 0.1:
        mapping.pop(H_HIT)
    rm = obj(c, 0x200, {0x58: _map_stub(c, mapping), 0x4c: _handle_stub(c),
                        0x60: rec_stub(c, 1, ret=sobj if r.random() < 0.8 else 0),
                        0x114: rec_stub(c, 4, ret=r.getrandbits(32))})
    # material
    clsinfo = rnd(c, 0x40)
    emu.w32(clsinfo + 0x23, 0x2000f0 if r.random() < 0.9 else r.choice((0x2000f1, 0x2000ef, r.getrandbits(32))))
    txt = emu.alloc(32, 4)
    emu.wbytes(txt, b'Mat_Concrete\0')
    ms = emu.alloc(16, 4)
    emu.w32(ms, txt)
    md = obj(c, 0x60, {0x1d8: _name_stub(c, ms)})
    emu.w32(md + 0xc, clsinfo)
    emu.w32(md + 0x18, pick(H_FX))
    emu.w32(md + 0x1c, pick(H_FX2))
    emu.w32(md + 0x20, pick(H_DECAL))
    emu.w32(md + 0x28, r.getrandbits(32))
    emu.wf32(md + 0x30, fv(0, 5))
    emu.w32(md + 0x38, r.getrandbits(32))
    mrec = rnd(c, 16)
    o1c = obj(c, 0x80, {0x74: rec_stub(c, 1, ret=r.getrandbits(32))})
    o18 = obj(c, 0x100, {0xf8: rec_stub(c, 1, ret=mrec if r.random() < 0.85 else 0)})
    sm = rnd(c, 0x40)
    emu.w32(sm + 0x1c, o1c)
    emu.w32(sm + 0x18, o18)
    snd = obj(c, 0x80, {0x58: rec_stub(c, 2, ret=r.choice((0, 1))), 0x5c: rec_stub(c, 1, ret=0x77)})
    eng = obj(c, 0x1c00, {0x1c0: rec_stub(c, 2, fldv=r.choice((0.0, 0.5, 1.0, r.random())))})
    emu.w32(eng + 0x9b, rm)
    emu.w32(eng + 0x1aa3, sm)
    emu.w32(eng + 0x1a9f, snd if r.random() < 0.7 else 0)
    emu.w8(eng + 0x68, r.choice((0, 0, 1)))
    emu.w32(0x70039c, eng)
    out = obj(c, 0x40, {0x2c: stub(c, 3, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x40, {0x20: stub(c, 2, ret=out)}))
    # patched callees
    patch_jmp(c, 0x4ba180, rec_stub(c, 1, ret=md if r.random() < 0.9 else 0))
    patch_jmp(c, 0x4db3b0, rec_stub(c, 0, ret=room))
    patch_jmp(c, 0x43ebb0, rec_stub(c, 7, ptrs={0: V3, 1: V3}, ret=r.getrandbits(32)))
    patch_jmp(c, 0x45bab0, rec_stub(c, 3))
    patch_jmp(c, 0x45bfd0, rec_stub(c, 1, skip=(0,), fills={0: (nrm_src, 3, 0)}))
    # projectile and COLI
    self = rnd(c, 0x100)
    emu.w32(self + 0x44, own)
    emu.wf32(self + 0x55, fv(0, 5000))
    emu.w32(self + 0x5d, pick(H_SH))
    emu.w32(self + 0x61, pick(H_W))
    emu.w32(self + 0x89, r.getrandbits(32))
    emu.w32(self + 0x91, r.choice((0, r.getrandbits(32))))
    coli = rnd(c, 0x80)
    for off in (0xc, 0x10, 0x14):
        emu.wf32(coli + off, fv(-3000, 3000))
    for off in (0x28, 0x2c, 0x30):
        emu.wf32(coli + off, fv())
    emu.w32(coli + 0x44, H_HIT)
    emu.mu.ctl_flush_tb()
    return [self, coli]


S(0x4ba7f0, 'ZProjectile::ShotImpact', 'thiscall', ret=None, gen=_gen)
