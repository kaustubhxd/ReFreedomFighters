"""wkit.py - shared spec helpers for the weapons batches (500-599). The stub builder is the batch 53 kit
(decomp-pilot/inline-batch45/harness/specs_s53.py), copied so both builds run the same machine-code stubs."""
import struct


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def vec(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n):
        c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
    return a


def stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None, adds=(), ofills=(), peeks=(), fldv=None, cdecl=False, rec_ecx=False):
    """A thiscall/stdcall stub in heap code: records its stack args (except `skip`) and a call count into a heap
    record (so the heap compare checks args and order-insensitive counts), optionally fills out-vectors, loads a
    float into ST0 (fld = address of a float, or fldv = a value) and returns `ret` in eax, popping 4*nargs."""
    if fldv is not None:
        fld = c.emu.alloc(4, 4)
        c.emu.wf32(fld, fldv)
    nrec = nargs + 1 + (len(copy[1]) if copy else 0) + len(peeks) + (1 if rec_ecx else 0)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    if rec_ecx:   # last record word = ECX (this) at the call
        code += b'\x89\x0d' + struct.pack('<I', rec + 4 * (nrec - 1))
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    if copy:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * copy[0]])
        for k, (off, kind) in enumerate(copy[1]):
            code += (b'\x8b\x50' if kind == 'd' else b'\x0f\xb6\x50') + bytes([off])
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * (nargs + 1 + k))
    for k, addr in enumerate(peeks):
        code += b'\xa1' + struct.pack('<I', addr) + b'\xa3' + struct.pack('<I', rec + 4 * (nrec - len(peeks) - (1 if rec_ecx else 0) + k))
    for ai, off, src, nd in ofills:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([off + 4 * j])
    for ai, src, nd in adds:
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
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 0 if cdecl else 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def seq_stub(c, nargs, rets):
    """A stub whose eax return walks through `rets` on successive calls (then repeats the last); records count."""
    tab = c.emu.alloc(4 * len(rets) + 8, 4)
    for i, v in enumerate(rets):
        c.emu.w32(tab + 4 * i, v)
    cnt = c.emu.alloc(4, 4)
    n = len(rets) - 1
    # mov eax,[cnt]; cmp eax,n; jbe +2? -> keep simple: eax=min(cnt,n); mov eax,[tab+eax*4]; inc [cnt]
    code = b'\xa1' + struct.pack('<I', cnt)                 # mov eax,[cnt]
    code += b'\x3d' + struct.pack('<I', n)                  # cmp eax,n
    code += b'\x76\x05'                                     # jbe +5
    code += b'\xb8' + struct.pack('<I', n)                  # mov eax,n
    code += b'\x8b\x04\x85' + struct.pack('<I', tab)        # mov eax,[tab+eax*4]
    code += b'\xff\x05' + struct.pack('<I', cnt)            # inc [cnt]
    code += b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def obj(c, size, slots, nvt=None):
    o = rnd(c, size)
    vt = c.emu.alloc(max(max(slots) + 4 if slots else 4, nvt or 0), 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def b(c, p):
    """A bool-ish eax: low byte 0 with probability p, garbage upper bytes otherwise random."""
    return c.rng.getrandbits(32) & (0xffffff00 if c.rng.random() < p else 0xffffffff) | (0 if c.rng.random() < 0.5 else 0)


def nonzero_b(c, p):
    v = b(c, p)
    return v


def f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def fedge(c):
    r = c.rng
    x = r.random()
    if x < 0.25:
        return 0.0
    if x < 0.3:
        return -0.0
    if x < 0.33:
        return float('nan')
    if x < 0.36:
        return r.choice((float('inf'), -float('inf'), 1e-40, -1e-40, 3.4e38))
    return r.uniform(-100.0, 100.0)


def sysobj(c, rm_slots, size=0xc00):
    """[0x70039c] engine object whose +0x9b is a render manager with the given vtable slots."""
    rm = obj(c, size, rm_slots)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, rm)
    c.emu.w32(0x70039c, so)
    return rm


def patch_jmp(c, addr, target):
    """Overwrite the exe code at addr with `jmp target` (both runs patch the same way; reset restores the image).
    For direct callees that cannot run in the emulator (fs:, stack probes), so the call lands in a heap stub."""
    c.emu.wbytes(addr, b'\xe9' + struct.pack('<i', target - (addr + 5)))
