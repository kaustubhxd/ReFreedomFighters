"""specs_s8808.py - hitreact batch 8808: ConstrainedParticleSystem::Move (0x546320). Exe code in both builds: vaddscalar4 0x443ef0,
PSVECSubtract 0x43e920, vaddscalar 0x451890, vscalar3 0x4e0d40, PSVECAdd 0x441940, vscalar 0x4e0d00 (all strict) and the CRT pow /
sin / sqrt through the exe's import slots. Patched to recording stubs (GUESS, not verified): ZeroOut 0x547a70 (fastcall this, n:
records n), FindFaces 0x545950 (counts), CheckCollision3 0x543a90 (counts and moves particle 0 by a per-case x offset, so the
order of the collision step against the surrounding loops is checked)."""
import struct
from pilot import S, F
from wkit import rnd, stub, obj, fedge
from dkit import patch_jmp


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _zero_stub(c):
    rec = c.emu.alloc(16, 4)
    # mov [rec], edx ; inc [rec+4] ; ret
    return _code(c, b'\x89\x15' + struct.pack('<I', rec) + b'\xff\x05' + struct.pack('<I', rec + 4) + b'\xc3')


def _count_stub(c):
    cnt = c.emu.alloc(4, 4)
    return _code(c, b'\xff\x05' + struct.pack('<I', cnt) + b'\xc3')


def _coll_stub(c, dx):
    cnt = c.emu.alloc(4, 4)
    k = c.emu.alloc(4, 4)
    c.emu.wf32(k, dx)
    # mov eax,[ecx+0xf]; movss xmm0,[eax+0xc]; addss xmm0,[k]; movss [eax+0xc],xmm0; inc [cnt]; ret
    code = b'\x8b\x41\x0f\xf3\x0f\x10\x40\x0c\xf3\x0f\x58\x05' + struct.pack('<I', k) + b'\xf3\x0f\x11\x40\x0c'
    code += b'\xff\x05' + struct.pack('<I', cnt) + b'\xc3'
    return _code(c, code)


def _pow_stub(emu):
    """CRT pow (SSE2 convention: x in xmm0, y in xmm1 -> xmm0). Both builds call it through the exe's import slot."""
    from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    import math

    def h(e, r):
        x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        y = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        try:
            v = math.pow(x, y)
        except (ValueError, OverflowError):
            v = float('nan')
        e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', v))[0])
        e.ret()
    if not getattr(emu, '_pow_stubbed', False):
        emu.stub_import('_libm_sse2_pow_precise', h)
        emu._pow_stubbed = True


def _gen(c):
    r = c.rng
    emu = c.emu
    _pow_stub(emu)
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    patch_jmp(c, 0x547a70, _zero_stub(c))
    patch_jmp(c, 0x545950, _count_stub(c))
    patch_jmp(c, 0x543a90, _coll_stub(c, r.uniform(-5, 5)))
    eng = rnd(c, 0x80)
    emu.w32(eng + 0x40, r.randrange(0, 1 << 22))
    emu.w32(0x70039c, eng)
    n = r.choice((1, 2, 5, 16, 16))
    base = emu.alloc(0x34 * n + 0x40, 4)
    emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * n + 0x40)))
    wl = r.uniform(-50, 150)
    for i in range(n):
        p = base + 0x34 * i
        for k in range(3):
            emu.wf32(p + 0xc + 4 * k, r.uniform(-200, 200) if k != 1 else r.choice((r.uniform(-60, 200), wl, wl + r.uniform(-30, 30))))
            emu.wf32(p + 0x18 + 4 * k, emu.r32(p + 0xc + 4 * k) and r.uniform(-200, 200))
            emu.wf32(p + 0x24 + 4 * k, r.uniform(-20, 20))
        emu.wf32(p + 0x30, 10000.0 if r.random() < 0.15 else r.choice((1.0, 1.0, 0.5)))
    if r.random() < 0.05:
        emu.wf32(base + 0x10, -20000.0)       # particle 0 below the fall-out height
    self = rnd(c, 0x80)
    emu.w32(self + 0xf, base)
    emu.w32(self + 0x28, n)
    emu.w8(self + 0x1b, 1 if r.random() < 0.05 else 0)
    emu.w32(self + 0x59, r.choice((0, 0, 0, 2, 5)))
    dt = r.choice((0.005, 0.02, 0.03, r.uniform(0.005, 0.03)))
    inw = r.choice((0, 0, 1, 0x100, 0x101))
    emu.mu.ctl_flush_tb()
    return [self, F(dt), inw, F(wl)]


S(0x546320, 'ConstrainedParticleSystem::Move', 'thiscall', ret='st0', gen=_gen)
