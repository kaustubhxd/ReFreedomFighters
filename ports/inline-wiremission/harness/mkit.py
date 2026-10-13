"""mkit.py - spec helpers for the missions decomp thread (batches 1400-1499).

Heap stubs record every argument and a call counter into a heap record, so the checker compares what each call
received (the heap is compared byte for byte). Machine-code stubs, so they behave the same in both runs."""
import struct


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def cstr(c, s):
    b = s.encode('latin-1') + b'\0'
    a = c.emu.alloc(len(b) + 4, 4)
    c.emu.wbytes(a, b)
    return a


def stub(c, nargs, ret=0, pop=None, this=False, rets=None, outs=(), skip=(), derefs=(), copy=None, fill=None):
    """A function stub. Records ECX (if this) and nargs stack args in a heap record (one slot per call is
    overwritten, plus a call counter). ret: EAX. pop: bytes popped (default 4*nargs, use 0 for cdecl).
    rets: list of return values used in turn (cycled by the counter, max 16).
    outs: [(argidx, value)] writes value to *(u32*)arg before returning. skip: arg indexes not recorded (stack
    addresses of locals). derefs: [(argidx, off)] also records the dword at [arg+off] (before outs are written).
    copy = (argidx, nmax, lenarg|None): records the bytes the pointer argument points to (length nmax, or the
    length argument), one area per call for the first 4 calls (then they wrap). Returns are unchanged; the areas
    are heap, so the checker compares them.
    fill = (ptrarg, src, lenarg): copies [len] bytes from src to the pointer argument (a read into a caller buffer)."""
    nrec = nargs + 2 + len(derefs)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    if this:
        code += b'\x89\x0d' + struct.pack('<I', rec + 4 * (nargs + 1))
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    if copy:
        ai, nmax, la = copy
        area = c.emu.alloc(4 * nmax + 4, 4)
        code += b'\x56\x57'
        code += b'\xa1' + struct.pack('<I', rec + 4 * nargs) + b'\x83\xe0\x03' + b'\x69\xc0' + struct.pack('<I', nmax)
        code += b'\x8d\xb8' + struct.pack('<I', area)
        code += b'\x8b\x74\x24' + bytes([12 + 4 * ai])
        code += (b'\x8b\x4c\x24' + bytes([12 + 4 * la])) if la is not None else (b'\xb9' + struct.pack('<I', nmax))
        code += b'\xf3\xa4\x5f\x5e'
    if fill:
        pa, src, la = fill
        code += b'\x56\x57' + b'\x8b\x7c\x24' + bytes([12 + 4 * pa]) + b'\xbe' + struct.pack('<I', src)
        code += b'\x8b\x4c\x24' + bytes([12 + 4 * la]) + b'\xf3\xa4\x5f\x5e'
    for k, (ai, off) in enumerate(derefs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai]) + b'\x8b\x40' + bytes([off]) + b'\xa3' + struct.pack('<I', rec + 4 * (nargs + 2 + k))
    for o in outs:   # (argidx, value[, size 4|1[, offset]]): *(arg + offset) = value
        ai, v = o[0], o[1]
        off = o[3] if len(o) > 3 else 0
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        code += (b'\xc6\x40' + bytes([off, v & 0xff])) if len(o) > 2 and o[2] == 1 else (b'\xc7\x40' + bytes([off]) + struct.pack('<I', v & 0xffffffff))
    if rets:
        tab = c.emu.alloc(64, 4)
        for i in range(16):
            c.emu.w32(tab + 4 * i, rets[i % len(rets)])
        # mov eax,[cnt]; and eax,15; mov eax,[tab+eax*4]
        code += b'\xa1' + struct.pack('<I', rec + 4 * nargs) + b'\x83\xe0\x0f' + b'\x8b\x04\x85' + struct.pack('<I', tab)
        code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    else:
        code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
        code += b'\xb8' + struct.pack('<I', ret & 0xffffffff)
    p = 4 * nargs if pop is None else pop
    code += (b'\xc2' + struct.pack('<H', p)) if p else b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def obj(c, size, slots, fill=True):
    """An object with a vtable; slots {byte offset: code address}. Other slots are 0 (a call faults)."""
    o = rnd(c, size) if fill else c.emu.alloc(size, 4)
    vt = c.emu.alloc(max(slots) + 4 if slots else 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def logger(c, nargs=3, skip=()):
    """[0x700390]: the debug-log object. slot 0x20(file, line) returns a printer; printer slot 0x2c is cdecl
    (printer, fmt, ...) and records the first nargs stack words (skip: indexes holding stack addresses)."""
    pr = obj(c, 8, {0x2c: stub(c, nargs, pop=0, skip=skip)})
    lg = obj(c, 8, {0x20: stub(c, 2, ret=pr, this=True)})
    c.emu.w32(0x700390, lg)
    return lg


def hook_stub(c, addr, nargs, this=False, ret=0, skip=(), copy=None, rets=None):
    """Replace the exe function at addr (in both runs: the port calls it through ext_<addr>) with a recorder like
    stub(). The hook stays for later cases; use it only for functions no spec wants to run for real."""
    rec = c.emu.alloc(4 * (nargs + 2), 4)
    area = c.emu.alloc(copy[1], 4) if copy else None   # copy = (argidx, n): bytes the pointer arg points to

    def h(e, r):
        esp = e.reg('esp')
        if copy:
            e.wbytes(area, e.rbytes(e.r32(esp + 4 + 4 * copy[0]), copy[1]))
        for i in range(nargs):
            if i not in skip:
                e.w32(rec + 4 * i, e.r32(esp + 4 + 4 * i))
        if this:
            e.w32(rec + 4 * (nargs + 1), e.reg('ecx'))
        k = e.r32(rec + 4 * nargs)
        e.w32(rec + 4 * nargs, k + 1)
        e.ret(eax=rets[k % len(rets)] if rets else ret, argbytes=4 * nargs)
    c.emu.hook(addr, h)
    return rec


# ---- CRT string imports (strchr, _memicmp, _stricmp) for striwcmp 0x4cc850, copied from
# inline-batch45/harness/specs_s54.py (C-locale ASCII folding).
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


def crt_strings(c):
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        c.emu.stub_import(nm, h)
