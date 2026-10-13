"""out_stubs.py - shared recording stubs for the decomp pilot specs (new 2026-10-12; no existing file is changed).

Use them for callees whose real bodies are owned elsewhere. Each stub is code in the heap, installed with
`jmp_patch` (a plain `jmp rel32`, which keeps the caller's eax) or returned as an address for a vtable slot.

What is here:
- rec_values(c, addr, nargs, value_args, ret_eax, ret_bytes): records ecx and the stack words listed in value_args
  (indices into the stack arguments; never a stack pointer) into heap slots, then returns ret_eax with `ret ret_bytes`.
- ptr_writer(c, nargs, ptr_idx, words, record_idx, ret_eax, ret_bytes): writes `words` (dwords) through the stack
  argument ptr_idx, then records the dwords behind the pointers listed in record_idx (values only). Use it for out-pointer
  calls: the caller's stack address is never logged.
- bump_alloc(c, pool_base, cdecl=True): a cdecl(size) bump allocator over a pool (returns the old bump pointer and advances
  by size). Its bump slot is returned so a spec can reset it per case.
- free_hook(c, addr, stack_words): a cdecl(p, size, ...) recorder: stores the listed stack words in heap slots, returns 0.
  The CRT free at 0x634273 is one such: pass stack_words=2 and the flag bit as a random choice in the spec if needed.
- vt_entry(c, nargs, impl_code): a code address to put into a vtable slot (thiscall, `ret 4*nargs`).

All helpers flush the translation cache for the patched code (`_flush_heap_code`) once per call.
"""
import struct

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _slot(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _jmp(c, addr, code_addr):
    c.emu.wbytes(addr, b'\xe9' + P((code_addr - (addr + 5)) & 0xffffffff))
    c.emu._image_dirty = True


def rec_values(c, addr, nargs, value_args, ret_eax=0, ret_bytes=None):
    """addr=None returns (code_address, slots) instead of patching an exe function (for vtable entries)."""
    """Record ecx and the stack words value_args (indices 0..nargs-1) into heap slots; ret ret_eax (stdcall/thiscall)."""
    if ret_bytes is None:
        ret_bytes = 4 * nargs
    slots = {'ecx': _slot(c)}
    for i in value_args:
        slots[i] = _slot(c)
    code = b'\x89\x0d' + P(slots['ecx'])
    for i in value_args:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + P(slots[i])
    code += b'\xb8' + P(ret_eax) + b'\xc2' + ret_bytes.to_bytes(2, 'little')
    if addr is None:
        return _code(c, code), slots
    _jmp(c, addr, _code(c, code))
    _flush(c)
    return slots


def ptr_writer(c, addr, nargs, ptr_idx, words, record_idx=(), ret_eax=0, ret_bytes=None):
    """addr=None returns (code_address, rec) instead of patching (for vtable entries)."""
    """Write `words` through stack argument ptr_idx; record the dwords behind the pointers in record_idx (heap slots).
    Returns the record slots (dict: 'ecx' and each record index -> list of slots, one per word)."""
    if ret_bytes is None:
        ret_bytes = 4 * nargs
    rec = {'ecx': _slot(c)}
    code = b'\x89\x0d' + P(rec['ecx'])
    code += b'\x8b\x44\x24' + bytes([4 + 4 * ptr_idx]) + b'\x8b\xd0'          # mov eax, [esp+ptr]; mov edx, eax
    for k, w in enumerate(words):
        code += b'\xc7\x42' + bytes([4 * k]) + P(w)                             # mov dword [edx+4k], w
    for i in record_idx:
        rec[i] = []
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\x8b\x00'               # mov eax, [esp+4+4i]; mov eax, [eax]
        s = _slot(c)
        rec[i].append(s)
        code += b'\xa3' + P(s)
    code += b'\xb8' + P(ret_eax) + b'\xc2' + ret_bytes.to_bytes(2, 'little')
    if addr is None:
        return _code(c, code), rec
    _jmp(c, addr, _code(c, code))
    _flush(c)
    return rec


def bump_alloc(c, pool_base, addr):
    """cdecl(size) at addr: returns the bump pointer and advances it by the size argument. Returns the bump slot."""
    bump = _slot(c)
    c.emu.w32(bump, pool_base)
    code = b'\x8b\x44\x24\x04' + b'\x8b\x15' + P(bump) + b'\x01\x05' + P(bump) + b'\x89\xd0' + b'\xc3'
    _jmp(c, addr, _code(c, code))
    _flush(c)
    return bump


def free_hook(c, addr, stack_words=2):
    """cdecl free-style hook at addr: records its first stack_words stack words (heap slots); returns nothing."""
    slots = [_slot(c) for _ in range(stack_words)]
    code = b''
    for i, s in enumerate(slots):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + P(s)
    code += b'\xc3'
    _jmp(c, addr, _code(c, code))
    _flush(c)
    return slots


def vt_entry(c, nargs, impl_code):
    """A thiscall code address for a vtable slot: impl_code is the body (without the ret)."""
    return _code(c, impl_code + b'\xc2' + (4 * nargs).to_bytes(2, 'little'))
