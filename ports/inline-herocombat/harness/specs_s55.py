"""specs_s55.py - inline session batch 55: ZFFHERO::ControlSpecialItems (throw and first-aid use).
Hero, item and render-manager vtable calls are heap stubs. striwcmp runs as exe code with the batch 54 Python
versions of the CRT imports."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None, adds=(), ofills=(), peeks=()):
    """copy = (argidx, [(off, 'd'|'b'), ...]) copies fields of the struct an arg points to into the record."""
    nrec = nargs + 1 + (len(copy[1]) if copy else 0) + len(peeks)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    if copy:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * copy[0]])
        for k, (off, kind) in enumerate(copy[1]):
            code += (b'\x8b\x50' if kind == 'd' else b'\x0f\xb6\x50') + bytes([off])
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * (nargs + 1 + k))
    for k, addr in enumerate(peeks):   # record a dword of memory at call time
        code += b'\xa1' + struct.pack('<I', addr) + b'\xa3' + struct.pack('<I', rec + 4 * (nrec - len(peeks) + k))
    for ai, off, src, nd in ofills:   # out = [arg]+off, filled from src
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([off + 4 * j])
    for ai, src, nd in adds:   # out[j] += src[j] (SSE single adds), like a local-to-world offset
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\xf3\x0f\x10\x40' + bytes([4 * j]) + b'\xf3\x0f\x58\x05' + struct.pack('<I', src + 4 * j)
            code += b'\xf3\x0f\x11\x40' + bytes([4 * j])
    for ai, src, nd in fills:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([4 * j])
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    if fld is not None:
        code += b'\xd9\x05' + struct.pack('<I', fld)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _obj(c, size, slots):
    o = _rnd(c, size)
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def _low(b):
    return b + 32 if 65 <= b <= 90 else b


def _rd(e, a, n=None):
    out = bytearray()
    while n is None or len(out) < n:
        b = e.mu.mem_read(a + len(out), 1)[0]
        if n is None and b == 0:
            break
        out.append(b)
    return bytes(out)


def _strchr(e, r):
    s, ch = e.arg32(0), e.arg32(1) & 0xff
    i = 0
    while True:
        b = e.mu.mem_read(s + i, 1)[0]
        if b == ch:
            e.ret(eax=s + i)
            return
        if b == 0:
            e.ret(eax=0)
            return
        i += 1


def _cmp(a, b, n):
    for i in range(n):
        x, y = _low(a[i]), _low(b[i])
        if x != y or x == 0:
            return (x - y) & 0xffffffff
    return 0


def _memicmp(e, r):
    n = e.arg32(2)
    e.ret(eax=_cmp(_rd(e, e.arg32(0), n), _rd(e, e.arg32(1), n), n) if n else 0)


def _stricmp(e, r):
    a, b = _rd(e, e.arg32(0)) + b'\0', _rd(e, e.arg32(1)) + b'\0'
    e.ret(eax=_cmp(a, b, max(len(a), len(b))) if len(a) == len(b) else _cmp(a.ljust(max(len(a), len(b)), b'\0'),
                                                                            b.ljust(max(len(a), len(b)), b'\0'),
                                                                            max(len(a), len(b))))


def _setup(c):
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        c.emu.stub_import(nm, h)



def _str(c, s):
    a = c.emu.alloc(len(s) + 8, 4)
    c.emu.wbytes(a, s + b'\0')
    return a


def _b(c, p):
    return c.rng.getrandbits(32) & (0xffffff00 if c.rng.random() < p else 0xffffffff)


NAMES = [b'FirstAid_Small', b'FirstAid_Medium', b'FirstAid_Large', b'firstaid_large', b'FirstAid_Large2',
         b'FirstAid_Smal', b'FirstAid_Mediumx', b'Grenade', b'', None]


def _csi(c):
    r = c.rng
    rm = _obj(c, 0x10, {0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    mag = _obj(c, 0x10, {0x330: _stub(c, 0, ret=r.choice((0xb, 0xc, 8, 8, 3, 0xd)))})
    ti = _rnd(c, 0x10)
    nm = r.choice(NAMES)
    c.emu.w32(ti + 4, 0 if nm is None else _str(c, nm))
    w = _obj(c, 0x40, {0x1e0: _stub(c, 1, ret=_b(c, 0.5)), 0x350: _stub(c, 0, ret=mag),
                       0x35c: _stub(c, 0, ret=r.choice((0, 1, 4))), 0x354: _stub(c, 0, ret=_b(c, 0.3)),
                       0x2e8: _stub(c, 0, ret=ti)})
    self = _obj(c, 0x900, {0x504: _stub(c, 0, ret=w if r.random() < 0.9 else 0),
                           0x3f0: _stub(c, 0, ret=r.choice((0, 0, 0, 2))),
                           0x5a4: _stub(c, 0, ret=_b(c, 0.3)),
                           0x3ec: _stub(c, 1, ret=r.getrandbits(32)), 0x3d8: _stub(c, 1)})
    for off, p in ((0x669, 0.15), (0x66a, 0.3), (0x66b, 0.0)):
        c.emu.wbytes(self + off, bytes([0 if r.random() < p else r.randint(1, 255)]))
    c.emu.mu.ctl_flush_tb()
    return [self]


def _setup(c):
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        c.emu.stub_import(nm, h)


S(0x58ff30, 'ZFFHERO::ControlSpecialItems', 'thiscall', None, ret='al', setup=_setup, gen=_csi,
  note='batch55; throw tree; striwcmp as exe code')
