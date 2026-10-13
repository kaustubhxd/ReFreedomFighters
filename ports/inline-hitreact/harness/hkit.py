"""hkit.py - spec helpers for the hitreact batches (8800-8899)."""
import struct


def rec_stub(c, nargs, ptrs=None, skip=(), ret=0, fldv=None, adds=None, fills=None, cond=None):
    """thiscall/stdcall stub popping 4*nargs. Records every stack arg not in `skip` and not in `ptrs`; for each
    ptrs[i] = [(off, 'd'|'b'), ...] records those fields of the pointed-to memory. adds[i] = (src, n): adds n floats from
    src to arg i's memory (a stand-in transform); fills[i] = (src, n, off): copies n dwords from src into arg i + off.
    cond = (i, testoff, recoff_list): record the dwords at recoff_list of arg i only when [arg i + testoff] != 0.
    Counts calls. fldv: float returned in ST0."""
    ptrs = ptrs or {}
    adds = adds or {}
    fills = fills or {}
    nrec = 1 + sum(1 for i in range(nargs) if i not in skip and i not in ptrs) + sum(len(v) for v in ptrs.values())
    if cond:
        nrec += len(cond[2])
    rec = c.emu.alloc(4 * nrec + 8, 4)
    k = 0
    code = b''
    for i in range(nargs):
        if i in skip or i in ptrs:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * k)
        k += 1
    for i, fields in ptrs.items():
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])
        for off, kind in fields:
            code += (b'\x8b\x50' if kind == 'd' else b'\x0f\xb6\x50') + bytes([off])
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * k)
            k += 1
    if cond:
        i, toff, offs = cond
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])
        body = b''
        for off in offs:
            body += b'\x8b\x50' + bytes([off]) + b'\x89\x15' + struct.pack('<I', rec + 4 * k)
            k += 1
        code += b'\x83\x78' + bytes([toff]) + b'\x00' + b'\x74' + bytes([len(body)]) + body
    for i, (src, n) in adds.items():
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])
        for j in range(n):
            code += b'\xf3\x0f\x10\x40' + bytes([4 * j]) + b'\xf3\x0f\x58\x05' + struct.pack('<I', src + 4 * j)
            code += b'\xf3\x0f\x11\x40' + bytes([4 * j])
    for i, (src, n, off) in fills.items():
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])
        for j in range(n):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([off + 4 * j])
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * k)
    if fldv is not None:
        fa = c.emu.alloc(4, 4)
        c.emu.wf32(fa, fldv)
        code += b'\xd9\x05' + struct.pack('<I', fa)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def fvec(c, vals):
    a = c.emu.alloc(4 * len(vals) + 16, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)
    return a
