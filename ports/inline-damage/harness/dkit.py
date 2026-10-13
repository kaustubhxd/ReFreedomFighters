"""dkit.py - spec helpers for the damage batches (600-699), on top of wkit.py."""
import struct


def coll_stub(c, zone, front):
    """ZIKLNKOBJ::GetBoneCollision stand-in (thiscall out, pos, dir; ret 0xc): records *pos and dir[2] and a call
    count, writes exactly 2 bytes {zone, front} at out, returns out."""
    rec = c.emu.alloc(16, 4)
    code = b'\x8b\x44\x24\x08\x8b\x00\xa3' + struct.pack('<I', rec)
    code += b'\x8b\x44\x24\x0c\x8b\x40\x08\xa3' + struct.pack('<I', rec + 4)
    code += b'\xff\x05' + struct.pack('<I', rec + 8)
    code += b'\x8b\x44\x24\x04\x66\xc7\x00' + struct.pack('<H', zone | (front << 8))
    code += b'\xc2\x0c\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def seq_rec_stub(c, nargs, rets):
    """thiscall/stdcall stub: k-th call records its first stack arg in rec[k] and returns rets[min(k, n-1)]."""
    n = len(rets)
    tab = c.emu.alloc(4 * n, 4)
    for i, v in enumerate(rets):
        c.emu.w32(tab + 4 * i, v & 0xffffffff)
    cnt = c.emu.alloc(4, 4)
    rec = c.emu.alloc(4 * 8, 4)
    code = b'\x8b\x0d' + struct.pack('<I', cnt)                     # mov ecx,[cnt]
    code += b'\x8b\x44\x24\x04'                                     # mov eax,[esp+4]
    code += b'\x83\xf9\x07\x77\x07'                                 # cmp ecx,7; ja +7
    code += b'\x89\x04\x8d' + struct.pack('<I', rec)                # mov [rec+ecx*4],eax
    code += b'\x83\xf9' + bytes([n - 1]) + b'\x76\x05'              # cmp ecx,n-1; jbe +5
    code += b'\xb9' + struct.pack('<I', n - 1)                      # mov ecx,n-1
    code += b'\x8b\x04\x8d' + struct.pack('<I', tab)                # mov eax,[tab+ecx*4]
    code += b'\xff\x05' + struct.pack('<I', cnt)                    # inc [cnt]
    code += b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def patch_jmp(c, addr, target):
    """Overwrite the exe function entry at addr with `jmp target` (both builds then call the same stub)."""
    c.emu.wbytes(addr, b'\xe9' + struct.pack('<i', target - (addr + 5)))


def byte_out_stub(c, nargs, out_arg, value):
    """thiscall stub: writes one byte `value` at the pointer in stack arg `out_arg`, records the other args'
    first dword... (only a call count), returns 0, pops 4*nargs."""
    cnt = c.emu.alloc(4, 4)
    code = b'\x8b\x44\x24' + bytes([4 + 4 * out_arg]) + b'\xc6\x00' + bytes([value & 0xff])
    code += b'\xff\x05' + struct.pack('<I', cnt) + b'\x31\xc0\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def iter_stub(c, handles):
    """List iterator 'next' (thiscall, arg = cookie pointer, ret 4): the k-th call returns handles[k] and writes
    cookie = 1 while k < len(handles), then returns 0 with cookie = 0."""
    n = len(handles)
    tab = c.emu.alloc(4 * (n + 1), 4)
    for i, h in enumerate(handles):
        c.emu.w32(tab + 4 * i, h)
    c.emu.w32(tab + 4 * n, 0)
    cnt = c.emu.alloc(4, 4)
    code = b'\x8b\x0d' + struct.pack('<I', cnt)                     # mov ecx,[cnt]
    code += b'\x83\xf9' + bytes([n]) + b'\x76\x05'                  # cmp ecx,n; jbe +5
    code += b'\xb9' + struct.pack('<I', n)                          # mov ecx,n
    code += b'\x8b\x04\x8d' + struct.pack('<I', tab)                # mov eax,[tab+ecx*4]
    code += b'\x8b\x54\x24\x04'                                     # mov edx,[esp+4]
    code += b'\x31\xc9' if False else b''
    code += b'\x3b\x0d' + struct.pack('<I', cnt)                    # (placeholder compare, no effect)
    code += b'\x8b\x0d' + struct.pack('<I', cnt)                    # mov ecx,[cnt]
    code += b'\x83\xf9' + bytes([n]) + b'\x0f\x92\xc1'              # cmp ecx,n; setb cl
    code += b'\x0f\xb6\xc9\x89\x0a'                                 # movzx ecx,cl; mov [edx],ecx
    code += b'\xff\x05' + struct.pack('<I', cnt)                    # inc [cnt]
    code += b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a
