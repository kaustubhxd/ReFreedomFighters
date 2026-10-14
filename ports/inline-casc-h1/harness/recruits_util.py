"""recruits_util.py - helpers shared by the recruits thread's spec files (decomp-pilot/inline-recruits/harness).

Callee stand-ins used here, all identical in the original and the port run:
  stub(c, nargs, ret, ...)   heap code stub (an x86 recorder): saves its stack args into a heap record, counts calls,
                             returns `ret` in EAX and pops 4*nargs (thiscall/stdcall). An arg given as ('p', n)
                             in `deref` copies n dwords from the pointer instead of saving the pointer, so pointers to
                             stack locals (which differ between the two runs) are compared by content.
  hook_rec(c, addr, ...)     same for a direct call to an exe function: a Python hook replaces the real code at addr.
                             All hooks are cleared at the start of every case (clear_hooks), so other specs see the
                             real code again.
"""
import struct
import pe_emu

HEAP_LO = pe_emu.HEAP_BASE
HEAP_HI = pe_emu.HEAP_BASE + pe_emu.HEAP_SIZE

_HOOKED = set()


def clear_hooks(c):
    for a in list(_HOOKED):
        c.emu.unhook(a)
    _HOOKED.clear()


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def stub(c, nargs, ret=0, deref=None, edx=None, pop=None):
    """Recorder stub. deref: {arg index: dword count} copies through the pointer. Returns the code address."""
    deref = deref or {}
    size = 0
    for i in range(nargs):
        size += 4 * deref.get(i, 1)
    rec = c.emu.alloc(size + 4, 4)
    code = b''
    p = rec
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])            # mov eax, [esp+4+4i]
        if i in deref:
            for k in range(deref[i]):
                code += b'\x8b\x50' + bytes([4 * k])            # mov edx, [eax+4k]
                code += b'\x89\x15' + struct.pack('<I', p)      # mov [p], edx
                p += 4
        else:
            code += b'\xa3' + struct.pack('<I', p)              # mov [p], eax
            p += 4
    code += b'\xff\x05' + struct.pack('<I', rec + size)          # inc dword [count]
    if edx is not None:
        code += b'\xba' + struct.pack('<I', edx & 0xffffffff)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff)
    n = 4 * nargs if pop is None else pop
    code += (b'\xc2' + struct.pack('<H', n)) if n else b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    c.emu.mu.ctl_flush_tb()
    return a


def stub_seq(c, nargs, rets):
    """Recorder stub that returns rets[0], rets[1], ... on successive calls (last value repeats).
    Records every call's args in its own row (up to len(rets)+4 rows)."""
    rows = len(rets) + 4
    rec = c.emu.alloc(4 * nargs * rows + 4, 4)
    tab = c.emu.alloc(4 * rows, 4)
    for i in range(rows):
        c.emu.w32(tab + 4 * i, rets[min(i, len(rets) - 1)] & 0xffffffff)
    cnt = rec + 4 * nargs * rows
    code = b'\x8b\x0d' + struct.pack('<I', cnt)                   # mov ecx, [cnt]
    code += b'\x83\xf9' + bytes([rows - 1])                       # cmp ecx, rows-1
    code += b'\x7e\x05' + b'\xb9' + struct.pack('<I', rows - 1)   # jle +5 ; mov ecx, rows-1
    code += b'\x6b\xd1' + bytes([4 * nargs])                      # imul edx, ecx, 4*nargs
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])              # mov eax, [esp+4+4i]
        code += b'\x89\x82' + struct.pack('<I', rec + 4 * i)      # mov [edx+rec+4i], eax
    code += b'\x8b\x04\x8d' + struct.pack('<I', tab)              # mov eax, [ecx*4+tab]
    code += b'\xff\x05' + struct.pack('<I', cnt)                  # inc dword [cnt]
    n = 4 * nargs
    code += (b'\xc2' + struct.pack('<H', n)) if n else b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    c.emu.mu.ctl_flush_tb()
    return a


def obj(c, size, slots, nslots=None):
    """Random-filled object whose vtable has the given {byte offset: code address} slots (others 0)."""
    o = rnd(c, size)
    top = max(slots) + 4 if slots else 4
    if nslots:
        top = max(top, 4 * nslots)
    vt = c.emu.alloc(top, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def _recorder(c, nargs, ret, pop, this, nullflag, deref, side, st0, stackmark=()):
    """Python recorder handler: one row of recorded args per call (8 rows, the last row is reused)."""
    deref = deref or {}
    # deref value d > 0: d dwords; d < 0: -d bytes (padded to whole dwords with zeros)
    dw = {i: (d if d > 0 else (-d + 3) // 4) for i, d in deref.items()}
    n = (1 if this else 0) + sum(dw.get(i, 1) for i in range(nargs))
    rows = 8
    rec = c.emu.alloc(4 * n * rows + 4, 4)
    cnt = rec + 4 * n * rows

    def h(emu, r):
        k = emu.r32(cnt)
        p = rec + 4 * n * min(k, rows - 1)
        if this:
            v = emu.reg('ecx')
            if this == 'mark' and not (HEAP_LO <= v < HEAP_HI):
                v = 0x57ac0000   # `this` on the caller's stack
            emu.w32(p, v)
            p += 4
        for i in range(nargs):
            v = emu.arg32(i)
            if i in nullflag:
                emu.w32(p, 1 if v else 0)
                p += 4
            elif i in stackmark:   # heap pointers recorded as is, anything else (the caller's stack) as a marker
                emu.w32(p, v if HEAP_LO <= v < HEAP_HI else 0x57ac0000)
                p += 4
            elif i in deref:
                if deref[i] > 0:
                    for j in range(deref[i]):
                        emu.w32(p, emu.r32(v + 4 * j))
                        p += 4
                else:
                    b = emu.rbytes(v, -deref[i])
                    b += bytes(4 * dw[i] - len(b))
                    emu.wbytes(p, b)
                    p += 4 * dw[i]
            else:
                emu.w32(p, v)
                p += 4
        emu.w32(cnt, k + 1)
        if side:
            side(emu, k)
        e = ret(emu, k) if callable(ret) else ret
        f = st0(emu, k) if callable(st0) else st0
        emu.ret(eax=e, argbytes=4 * nargs if pop is None else pop, st0=f)
    return h, rec


def hook_rec(c, addr, nargs, ret=0, pop=None, this=False, nullflag=(), deref=None, side=None, st0=None, stackmark=()):
    """Replace the exe function at addr by a recorder (Python hook). Records ECX too when this=True.
    nullflag: arg indices recorded only as 0/1 (output pointers into the caller's stack). deref: {arg index: dword
    count} records the pointed-to dwords instead of the pointer. ret: value or callable(emu, call_no).
    side(emu, call_no): extra effect before returning. st0: float (or callable) returned on the x87 stack."""
    h, rec = _recorder(c, nargs, ret, pop, this, nullflag, deref, side, st0, stackmark)
    c.emu.hook(addr, h)
    _HOOKED.add(addr)
    return rec


def pystub(c, nargs, ret=0, pop=None, this=False, nullflag=(), deref=None, side=None, st0=None, stackmark=()):
    """Same recorder as hook_rec, as a code address for a vtable slot (thiscall/stdcall, callee pops)."""
    h, rec = _recorder(c, nargs, ret, pop, this, nullflag, deref, side, st0, stackmark)
    return c.emu.stub_fn('recorder', h)


def sysobj(c, slots=None, table_slots=None, rand=None, table_size=0x20):
    """Engine system object at 0x70039c: vtable slots as given; 0x1c0 returns `rand` on the x87 stack when given;
    +0x9b = object table with table_slots."""
    so = rnd(c, 0x2000)   # big enough for fields up to +0x1b5d (multiplayer flag)
    vt = c.emu.alloc(0x200, 4)
    for off, code in (slots or {}).items():
        c.emu.w32(vt + off, code)
    if rand is not None:   # engine random: records (file, line), returns `rand` on the x87 stack
        c.emu.w32(vt + 0x1c0, pystub(c, 2, st0=rand))
    c.emu.w32(so, vt)
    c.emu.w32(so + 0x9b, obj(c, table_size, table_slots or {}))
    c.emu.w32(0x70039c, so)
    return so


def reftab_vt(c, elems, find=None, count=0, end_value=0):
    """Fake REFTAB vtable. elems: list of dwords for iteration. Slots: 0 scalar deleting dtor (recorder), 0x14 count,
    0x2c find(id) -> find.get(id, 0), 0x3c remove(id) (recorder), 0x4c begin(iter), 0x5c next(iter) -> element with
    iter[0] = 1 while valid (0 and end_value after the end), 0x64 next(iter) -> element or 0, 0x44 remove the
    element the iterator last returned (recorded).
    The iterator index lives in iter[1] (on the caller's stack, so both runs see their own copy)."""
    find = find or {}
    e = c.emu

    def begin(emu, r):
        it = emu.arg32(0)
        emu.w32(it, 0)
        emu.w32(it + 4, 0)
        emu.ret(0, 4)

    def nxt5c(emu, r):
        it = emu.arg32(0)
        i = emu.r32(it + 4)
        emu.w32(it + 4, i + 1)
        if i < len(elems):
            emu.w32(it, 1)
            emu.ret(elems[i], 4)
        else:
            emu.w32(it, 0)
            emu.ret(end_value, 4)

    def nxt64(emu, r):
        it = emu.arg32(0)
        i = emu.r32(it + 4)
        emu.w32(it + 4, i + 1)
        emu.ret(elems[i] if i < len(elems) else 0, 4)

    rem = e.alloc(4 * 9, 4)   # removed elements (8 rows) and a count

    def remove(emu, r):   # slot 0x44: remove the element the iterator last returned
        it = emu.arg32(0)
        i = emu.r32(it + 4)
        k = emu.r32(rem + 32)
        if 0 < i <= len(elems):
            emu.w32(rem + 4 * min(k, 7), elems[i - 1])
            del elems[i - 1]
            emu.w32(it + 4, i - 1)
        else:
            emu.w32(rem + 4 * min(k, 7), 0xdead)
        emu.w32(rem + 32, k + 1)
        emu.ret(0, 4)

    def fnd(emu, r):
        emu.ret(find.get(emu.arg32(0), 0), 4)
    vt = e.alloc(0x80, 4)
    e.w32(vt + 0x00, pystub(c, 1, this=True))
    e.w32(vt + 0x14, pystub(c, 0, ret=count))
    e.w32(vt + 0x2c, e.stub_fn('reftab find', fnd))
    e.w32(vt + 0x3c, pystub(c, 1, this=True))
    e.w32(vt + 0x44, e.stub_fn('reftab remove current', remove))
    e.w32(vt + 0x4c, e.stub_fn('reftab begin', begin))
    e.w32(vt + 0x5c, e.stub_fn('reftab next', nxt5c))
    e.w32(vt + 0x64, e.stub_fn('reftab next ptr', nxt64))
    return vt


def reftab(c, elems, find=None, count=0, end_value=0, size=0x40):
    o = rnd(c, size)
    c.emu.w32(o, reftab_vt(c, elems, find, count, end_value))
    return o


def logger(c, nargs=2, slot=0x2c):
    """Engine log/assert object at 0x700390: slot 0x20 (file, line) returns a log object whose slot `slot` is a cdecl
    varargs print recorded with `nargs` stack args (the log object, the format, then format args)."""
    lo = obj(c, 0x20, {slot: pystub(c, nargs, pop=0)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    c.emu.w32(0x700390, lg)
    return lg


def stub_memmove(c):
    """MSVCRT memmove through the IAT (0x676278), cdecl (dst, src, n) -> dst."""
    def h(e, r):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        if n:
            e.wbytes(d, e.rbytes(s_, n))
        e.ret(eax=d, argbytes=0)
    c.emu.stub_import('memmove', h)


def stub_memset(c):
    """CRT memset through its import (thunk 0x634d10), cdecl (dst, value, n) -> dst."""
    def h(e, r):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        if n:
            e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d, argbytes=0)
    c.emu.stub_import('memset', h)
