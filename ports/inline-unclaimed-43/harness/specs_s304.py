"""specs_s304.py - unclaimed-43 batch 304: input-action probe (0x43ad20), thiscall, one stack argument, ret 4, bool in al.
The argument is a logging object whose slot 0x10 takes (buffer, 0x100). The mock logs the header dword and the two
NUL-terminated strings the probe copies into the buffer (the first at buf[0], the second at buf[0x7c]) and the dword the
probe stores at buf[0xf8], so the log shows exactly what the probe passed on. Strings are at most 40 bytes, so the copies stay inside the 256-byte frame.
X = 0 (no type-3 or type-1 record) reads the dword at address 8 and the byte at address 0; the spec zeroes both so that
the source is the empty string (the low page is mapped by the harness and is the same for both runs)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

NSLOTS = 0x14 // 4        # slot 0x10 is the callee the probe makes


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords):
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            f = impl.get(off)
            eax, st0 = (f(e, args) if f else (0, None))
            e.ret(eax=eax, argbytes=4 * n, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _cstr(c, n):
    a = c.emu.alloc(n + 1, 1)
    c.emu.wbytes(a, bytes(c.rng.randrange(65, 123) for _ in range(n)) + b'\0')
    return a


def _probe_log(e, a):
    ptr = a[0]
    hdr = e.r32(ptr)
    raw = e.rbytes(ptr + 4, 0xfc)
    s1 = raw[:0x7c].split(b'\0', 1)[0]
    s2 = raw[0x7c:].split(b'\0', 1)[0]
    e.calllog.append(('probe_buf', 0, 0, (hdr, a[1], s1, s2, raw[0xf8:0xfc])))
    return (None, None)


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x100)
    edi = 0 if r.random() < 0.15 else r.getrandbits(32)
    c.emu.w32(o + 0x46, edi)
    c.emu.wbytes(o + 0x34, bytes([1 if r.random() < 0.1 else 0]))
    c.emu.w32(o + 8, _cstr(c, r.randrange(0, 41)))
    s1 = _cstr(c, r.randrange(0, 41))
    x = r.random()
    if x < 0.15:
        p = 0
        c.emu.w32(8, 0)
        c.emu.w32(0, 0)
    elif x < 0.5:
        blk = E.zero_obj(c, 0x20)
        p = blk + 4
        c.emu.w32(p, 3)
        c.emu.w32(blk + 8, s1)
    else:
        pb = E.zero_obj(c, 0x20)
        vb = E.zero_obj(c, 0x20)
        c.emu.w32(pb, 1)
        c.emu.w32(pb + 8, vb + 4)
        c.emu.w32(vb + 8, s1)
        p = pb
    c.emu.w32(o + 0xc, p)
    obj = E.zero_obj(c, 0x40)
    c.emu.w32(obj, _vtable(c, 'ZINPUTPROBE', NSLOTS, {0x10: _probe_log}, {0x10: 2}))
    c.emu.mu.ctl_flush_tb()
    return [o, obj]


S(0x43ad20, 'ZInputActions probe (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-43 batch 304; callee slot 0x10 logs the header and both strings it is given')
