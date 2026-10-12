"""specs_s8802.py - hitreact batch 8802: the StartAndHitRagdoll script native (0x55cae0). The script argument getter
0x5003d0 and return setter 0x5002f0 run as exe code in both builds (args: {array{base, ?, count}, offset, nargs}, 8-byte
value slots); HitRagdoll 0x466c10 is exe code (batch 8800) and forwards to the bone modifier's slot 0x3c (a stub)."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge


def _argobj(c, vals, tbyte=0):
    emu = c.emu
    base = emu.alloc(8 * len(vals) + 16, 8)
    for i, v in enumerate(vals):
        emu.wbytes(base + 8 * i, struct.pack('<f', v) + bytes([tbyte, 0, 0, 0]))
    arr = rnd(c, 16)
    emu.w32(arr, base)
    emu.w32(arr + 8, len(vals))
    a = rnd(c, 16)
    emu.w32(a, arr)
    emu.w32(a + 4, 0)
    emu.w32(a + 8, len(vals))
    return a


def _vec2_stub(c):
    """thiscall (pos*, force*, float), ret 0xc: records pos[0..2], force[0..2], the float bits and a call count."""
    rec = c.emu.alloc(4 * 8, 4)
    code = b''
    for ai in (0, 1):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])                  # mov eax,[esp+4+4ai]
        for j in range(3):
            code += b'\x8b\x50' + bytes([4 * j])                         # mov edx,[eax+4j]
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * (3 * ai + j))
    code += b'\x8b\x44\x24\x0c\xa3' + struct.pack('<I', rec + 24)       # strength bits
    code += b'\xff\x05' + struct.pack('<I', rec + 28)
    code += b'\xc2\x0c\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _gen(c):
    r = c.rng
    emu = c.emu
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    out = obj(c, 0x40, {0x2c: stub(c, 3, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x40, {0x20: stub(c, 2, ret=out)}))
    bm = obj(c, 0x100, {0x34: stub(c, 0, ret=r.choice((0, 0, 1, 0x100, 0xffffff01))), 0x3c: _vec2_stub(c)})
    actor = obj(c, 0x100, {0x354: stub(c, 2, ret=r.choice((0, 1, 0x100, 0xffffff01)))})
    emu.w32(actor + 0x6c, bm)
    self = rnd(c, 0x40)
    emu.w32(self + 0x1c, actor)
    vals = [r.choice((r.uniform(-2000, 2000), 0.0, fedge(c))) for _ in range(6)] + [r.choice((1.0, 2.0, 0.2, fedge(c)))]
    call = rnd(c, 16)
    emu.w32(call + 4, _argobj(c, vals))
    emu.w32(call + 8, _argobj(c, [0.0], tbyte=r.choice((0, 1, 1, 2))))
    emu.mu.ctl_flush_tb()
    return [self, call]


S(0x55cae0, 'ZFFActorIf::StartAndHitRagdoll', 'thiscall', ret=None, gen=_gen)
