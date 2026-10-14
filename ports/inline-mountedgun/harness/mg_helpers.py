"""mg_helpers.py - shared spec helpers for the mounted gun batches (300-399).
_rnd/_stub/_obj are copied from inline-batch45/harness/specs_s55.py: a stub is a small piece of machine code on the
heap that records its stack args and a call counter into a heap record (so the heap compare checks them), optionally
fills out-buffers, and returns a fixed value with the right callee-pop."""
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None, adds=(), ofills=(), peeks=(), pop=None, this=False):
    """copy = (argidx, [(off, 'd'|'b'), ...]) copies fields of the struct an arg points to into the record.
    pop: bytes the stub pops (default 4 * nargs; 0 for cdecl). this: also record ECX (added for batch 301)."""
    nrec = nargs + 1 + (len(copy[1]) if copy else 0) + len(peeks) + (1 if this else 0)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    if this:
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
    for k, addr in enumerate(peeks):   # record a dword of memory at call time
        code += b'\xa1' + struct.pack('<I', addr) + b'\xa3' + struct.pack('<I', rec + 4 * (nargs + 1 + (len(copy[1]) if copy else 0) + k))
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
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + (b'\xc2' + struct.pack('<H', 4 * nargs if pop is None else pop) if (pop is None and nargs) or pop else b'\xc3')
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




def engine(c, rm_slots=None, size=0x200):
    """Engine object at 0x70039c with random bytes; its +0x9b manager gets the given vtable slots."""
    sysobj = _rnd(c, size)
    rm = None
    if rm_slots is not None:
        rm = _obj(c, 0x40, rm_slots)
        c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    return sysobj, rm


def flush(c):
    c.emu.mu.ctl_flush_tb()


def b8(c, p0):
    """A byte-ish dword: low byte zero with probability p0, else random (for bool returns tested via al)."""
    return c.rng.getrandbits(32) & (0xffffff00 if c.rng.random() < p0 else 0xffffffff)


def dispatch(c, table, default=0, argbytes=4):
    """Stub for a lookup slot (e.g. object manager slot 0x58): returns table[first stack arg], else default.
    Pure function of its argument, so the order and count of calls are not recorded here."""
    code = b''
    for k, v in table.items():
        # cmp dword [esp+4], k ; jne +6 ; mov eax, v ; ret argbytes
        code += b'\x81\x7c\x24\x04' + struct.pack('<I', k & 0xffffffff) + b'\x75\x08'
        code += b'\xb8' + struct.pack('<I', v & 0xffffffff) + b'\xc2' + struct.pack('<H', argbytes)
    code += b'\xb8' + struct.pack('<I', default & 0xffffffff) + b'\xc2' + struct.pack('<H', argbytes)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def rec_stub(c, nargs, deref, ret=0, fld=None):
    """Stub recording, per call, the dwords each pointer arg points to: deref = {argidx: ndwords}. Each call appends
    to a log (up to 8 calls); the record holds a counter then the copied dwords. Pointer values are not recorded
    (stack addresses differ between the original and the port)."""
    per = sum(deref.values())
    rec = c.emu.alloc(4 * (1 + 8 * per), 4)
    code = b''
    # esi-free: use edx as the log cursor = rec + 4 + 4*per*count
    code += b'\x52\x51\x50'                                   # push edx; push ecx; push eax
    code += b'\xa1' + struct.pack('<I', rec)                  # mov eax, [rec]
    code += b'\x83\xf8\x08\x73' + bytes([0])                  # cmp eax, 8 ; jae end (patched below)
    jae_at = len(code) - 1
    code += b'\x69\xc0' + struct.pack('<I', 4 * per)          # imul eax, eax, 4*per
    code += b'\x8d\x90' + struct.pack('<I', rec + 4)          # lea edx, [eax + rec + 4]
    for ai, nd in sorted(deref.items()):
        code += b'\x8b\x4c\x24' + bytes([16 + 4 * ai])        # mov ecx, [esp + 16 + 4*ai]  (3 pushes + ret)
        for j in range(nd):
            code += b'\x8b\x41' + bytes([4 * j])              # mov eax, [ecx + 4j]
            code += b'\x89\x02'                               # mov [edx], eax
            code += b'\x83\xc2\x04'                           # add edx, 4
    end = len(code)
    code = code[:jae_at] + bytes([end - jae_at - 1]) + code[jae_at + 1:]
    code += b'\xff\x05' + struct.pack('<I', rec)              # inc dword [rec]
    code += b'\x58\x59\x5a'                                   # pop eax; pop ecx; pop edx
    if fld is not None:
        code += b'\xd9\x05' + struct.pack('<I', fld)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff)
    code += (b'\xc2' + struct.pack('<H', 4 * nargs)) if nargs else b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


# ---- CRT imports used by striwcmp (0x4cc850) when it runs as exe code; copied from inline-batch45 specs_s55.py
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




def crt_setup(c):
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        c.emu.stub_import(nm, h)


def cstr(c, s):
    a = c.emu.alloc(len(s) + 8, 4)
    c.emu.wbytes(a, s + b'\0')
    return a


def new_log(c, n=96):
    """A shared ordered call log: [count] then n entries of 3 dwords (tag, a0, a1)."""
    log = c.emu.alloc(4 + 12 * n, 4)
    c.vars['log_n'] = n
    return log


def log_stub(c, log, tag, nargs, ret=0, stream=None, args=(0, 1), chain=None):
    """Appends (tag, first two stack args) to `log` per call. With stream (address of a cursor dword pointing at
    a dword stream): instead of logging arg0 (a pointer), reads the next stream dword, writes it to [arg0] and
    logs it."""
    n = c.vars.get('log_n', 96)
    code = b'\x52\x50'                                                    # push edx; push eax
    code += b'\x8b\x15' + struct.pack('<I', log)                          # mov edx, [log]
    code += b'\x81\xfa' + struct.pack('<I', n) + b'\x73\x00'              # cmp edx, n ; jae end
    jae = len(code) - 1
    code += b'\x6b\xd2\x0c'                                               # imul edx, edx, 12
    code += b'\x81\xc2' + struct.pack('<I', log + 4)                      # add edx, log+4
    code += b'\xc7\x02' + struct.pack('<I', tag)                          # mov dword [edx], tag
    if stream is not None:
        code += b'\xa1' + struct.pack('<I', stream)                       # mov eax, [stream]
        code += b'\x8b\x00'                                               # mov eax, [eax]
        code += b'\x89\x42\x04'                                           # mov [edx+4], eax
        code += b'\x83\x05' + struct.pack('<I', stream) + b'\x04'         # add dword [stream], 4
        code += b'\x8b\x54\x24\x0c'                                       # mov edx, [esp+12] (arg0)
        code += b'\x89\x02'                                               # mov [edx], eax
    else:
        # args: which two stack args to log (default the first two)
        if nargs > args[0]:
            code += b'\x8b\x44\x24' + bytes([12 + 4 * args[0]]) + b'\x89\x42\x04'   # mov eax,[esp+..]; mov [edx+4],eax
        if nargs > args[1]:
            code += b'\x8b\x44\x24' + bytes([12 + 4 * args[1]]) + b'\x89\x42\x08'   # mov eax,[esp+..]; mov [edx+8],eax
    code += b'\xff\x05' + struct.pack('<I', log)                          # inc dword [log]
    end = len(code)
    code = code[:jae] + bytes([end - jae - 1]) + code[jae + 1:]
    code += b'\x58\x5a'                                                   # pop eax; pop edx
    if chain is not None:   # log, then continue into another stub (e.g. a dispatcher) with the stack untouched
        a = c.emu.alloc(len(code) + 16, 16)
        code += b'\xe9' + struct.pack('<i', chain - (a + len(code) + 5))
        c.emu.wbytes(a, code)
        return a
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff)
    code += (b'\xc2' + struct.pack('<H', 4 * nargs)) if nargs else b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def cmd_stub(c, writes, fallback):
    """Event Command slot (thiscall id, data, z; ret 0xc): for an id in `writes` stores writes[id] at [data] and returns
    0 (data is then a caller's local, whose address is not logged); any other id jumps to `fallback` (e.g. a log_stub
    with 3 args) so the call is logged."""
    code = b''
    for k, v in writes.items():
        code += b'\x66\x81\x7c\x24\x04' + struct.pack('<H', k & 0xffff)          # cmp word [esp+4], k
        code += b'\x75\x0f'                                                       # jne +15
        code += b'\x8b\x44\x24\x08'                                               # mov eax, [esp+8]
        code += b'\xc7\x00' + struct.pack('<I', v & 0xffffffff)                   # mov dword [eax], v
        code += b'\x31\xc0\xc2\x0c\x00'                                           # xor eax,eax; ret 0xc
    code += b'\xe9' + b'\0\0\0\0'                                                 # jmp fallback
    a = c.emu.alloc(len(code) + 16, 16)
    rel = fallback - (a + len(code))
    code = code[:-4] + struct.pack('<i', rel)
    c.emu.wbytes(a, code)
    return a


def make_block(c, vals, first=0, slack=0):
    """A script parameter block: +0 array, +4 first index, +8 count; array: +0 values (8 bytes: dword, type byte),
    +8 size. vals = [(value, type)]."""
    n = first + len(vals) + slack
    data = c.emu.alloc(8 * max(n, 1), 4)
    for i in range(n):
        c.emu.w32(data + 8 * i, c.rng.getrandbits(32))
        c.emu.w32(data + 8 * i + 4, c.rng.getrandbits(32) & 0xffffff07)
    for i, (v, t) in enumerate(vals):
        c.emu.w32(data + 8 * (first + i), v)
        c.emu.w8(data + 8 * (first + i) + 4, t)
    arr = _rnd(c, 0x10)
    c.emu.w32(arr, data)
    c.emu.w32(arr + 8, n)
    blk = _rnd(c, 0x10)
    c.emu.w32(blk, arr)
    c.emu.w32(blk + 4, first)
    c.emu.w32(blk + 8, len(vals) + slack)
    return blk, data + 8 * first
