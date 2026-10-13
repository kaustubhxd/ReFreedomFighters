"""camgen.py - input helpers shared by the camera thread's spec files."""
import struct

SYS = 0x70039c  # ZSysInterface* global


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


SPECIAL = [0.0, -0.0, 1.0, -1.0, 0.5, 1e-30, -1e-30, 3.4e38, -3.4e38, float('inf'), float('-inf')]
NAN_BITS = [0x7fc00000, 0xffc00000, 0x7f800001, 0xff812345]


def fbits(c):
    """Random float32 bits: mostly ordinary values, some specials, NaNs (quiet and signalling)."""
    r = c.rng
    x = r.random()
    if x < 0.6:
        return struct.unpack('<I', struct.pack('<f', r.uniform(-2000, 2000)))[0]
    if x < 0.75:
        return struct.unpack('<I', struct.pack('<f', r.choice(SPECIAL)))[0]
    if x < 0.85:
        return r.choice(NAN_BITS)
    return r.getrandbits(32)


def f32(c):
    return struct.unpack('<f', struct.pack('<I', fbits(c)))[0]


class Log:
    """A heap buffer that stub handlers append words to, so call order and arguments are compared."""
    def __init__(self, c, words=256):
        self.emu = c.emu
        self.base = c.emu.alloc(4 * words, 4)
        self.n = 0
        self.cap = words

    def put(self, *ws):
        for w in ws:
            if self.n < self.cap:
                self.emu.w32(self.base + 4 * self.n, w)
                self.n += 1


def handler(log, tag, nargs, eax=None, st0=None):
    """A stub handler for a thiscall/stdcall callee: logs tag, ECX and nargs stack words, returns eax/st0."""
    def h(e, r):
        log.put(tag, e.reg('ecx'), *[e.arg32(i) for i in range(nargs)])
        v = eax(e) if callable(eax) else eax
        e.ret(eax=v, argbytes=4 * nargs, st0=st0)
    return h


def sys_with_mgr(c, size=0x2000):
    """Install a fake ZSysInterface at 0x70039c; returns it. Caller fills fields."""
    s = rnd(c, size)
    c.emu.w32(SYS, s)
    return s


def handler2(c, log, tag, spec, eax=None, st0=None):
    """Stub handler with per-argument handling. spec is a string, one letter per stack arg:
    'w' log the word; 'p' a pointer to a stack local: log nothing for its value; 'v' pointer to 3 floats: log the
    12 bytes, then overwrite them with random floats; 'o' an output buffer of 0x24 bytes (a 3x3 matrix), 'q' of 12 bytes (a vector): fill with random bytes; 'W' an output dword: write a random value; 'F' an output vector: write 3 random floats; '2' an output of two floats; 'f' an output float: write one random float; 'O' an output 3x3 matrix: write 9 floats;
    'C' a COLI record:
    log its start, direction, fraction, +0x44 and flag byte.
    ECX is logged unless spec starts with '-'."""
    logecx = not spec.startswith('-')
    spec = spec.lstrip('-')

    def h(e, r):
        log.put(tag)
        if logecx:
            log.put(e.reg('ecx'))
        for i, k in enumerate(spec):
            a = e.arg32(i)
            if k == 'w':
                log.put(a)
            elif k == 'v':
                log.put(e.r32(a), e.r32(a + 4), e.r32(a + 8))
                for j in range(3):
                    e.w32(a + 4 * j, fbits(c))
            elif k == 'o':
                e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x24)))
            elif k == 'C':  # a COLI (line test record) on the stack: log start, dir, fraction, +0x44, flag byte
                log.put(*[e.r32(a + 4 * j) for j in range(6)], e.r32(a + 0x34), e.r32(a + 0x44), e.r8(a + 0x6c))
            elif k == 'F':
                for j in range(3):
                    e.w32(a + 4 * j, fbits(c))
            elif k == '2':
                e.w32(a, fbits(c))
                e.w32(a + 4, fbits(c))
            elif k == 'f':
                e.w32(a, fbits(c))
            elif k == 'O':
                for j in range(9):
                    e.w32(a + 4 * j, fbits(c) if c.rng.random() < 0.2 else struct.unpack('<I', struct.pack('<f', c.rng.uniform(-1, 1)))[0])
            elif k == 'W':
                e.w32(a, c.rng.getrandbits(32))
            elif k == 'q':
                e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(12)))
        v = eax(e) if callable(eax) else eax
        e.ret(eax=v, argbytes=4 * len(spec), st0=st0)
    return h


def _boxenv(c, log):
    """Box manager at 0x70038c and geometry manager; returns nothing (all via logs)."""
    box = 0
    if c.rng.random() < 0.85:
        box = rnd(c, 16)
        c.emu.w32(box + 4, fbits(c))
    bm = c.emu.fake_object('boxmgr', 0x10, slots={0xcc: handler(log, 0xcc, 1, eax=box)})
    c.emu.w32(0x70038c, bm)
    g = 0
    if c.rng.random() < 0.85:
        g = c.emu.fake_object('boxgeom', 0x10, slots={
            0x8c: handler2(c, log, 0x8c, 'v', eax=c.rng.getrandbits(32)),
            0x184: handler2(c, log, 0x184, 'v', eax=lambda e: c.rng.getrandbits(32)),
            0x80: handler2(c, log, 0x80, 'oq', eax=c.rng.getrandbits(32))})
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)


def pow_stub(e, r):
    """CRT pow (xmm0 ** xmm1 -> xmm0) for _libm_sse2_pow_precise, which pe_emu leaves unstubbed."""
    from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
    y = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
    try:
        z = x ** y
        z = float('nan') if isinstance(z, complex) else float(z)
    except (OverflowError, ZeroDivisionError, ValueError):
        z = float('inf')
    e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    e.ret()
