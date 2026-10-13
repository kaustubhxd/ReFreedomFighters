"""specs_s1139.py - collision thread batch 1139 (GUESS name): 0x4364e0 (constructor; SEH frame not reproduced). Callees, all
stubbed BY ADDRESS or as fakes: 0x41e290 (cdecl allocator: returns successive arena blocks; logs its size), 0x4ccbe0 (record
constructor: records ECX and its two arguments, returns a per-case EAX, pops 8), 0x437440 (records ECX and its two arguments,
pops 8), the logger 0x700390 (slot 0x20 opens a stream; the stream's slot 0x2c is cdecl and records), B's vtable slot 4 (bool
per case) and slot 0 (the list pointer). The list has k records of 0x1c bytes with a zero terminator (k = 0 when its first
dword is zero). The string may be NULL."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _ctor(c):
    e, r = c.emu, c.rng
    arena = e.alloc(0x400, 16)
    e.wbytes(arena, bytes(0x400))
    cnt = [0]

    def alloc(em, rr):
        size = em.arg32(0)
        em.calllog.append(('41e290', size))
        ptr = arena + (0 if cnt[0] == 0 else 0x100)
        cnt[0] += 1
        em.ret(eax=ptr, argbytes=0)                  # cdecl: the caller cleans the argument
    _stub_addr(c, 0x41e290, 'alloc_41e290', alloc)

    rec_ret = r.getrandbits(32) | 1

    def ctor(em, rr):
        em.calllog.append(('4ccbe0', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(eax=rec_ret, argbytes=8)
    _stub_addr(c, 0x4ccbe0, 'ctor_4ccbe0', ctor)

    def f437(em, rr):
        em.calllog.append(('437440', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    _stub_addr(c, 0x437440, 'f_437440', f437)

    # the list: k records (0x1c bytes) with a zero terminator; k = 0 leaves the first dword zero
    k = r.randrange(0, 5)
    L = e.alloc(0x1c * (k + 2) + 0x20, 16)
    for j in range(k):
        e.w32(L + 0x1c * j, r.getrandbits(32) | 1)     # k records with a non-zero first dword
    e.w32(L + 0x1c * k, 0)                              # the terminator (k = 0: the first dword is zero)

    lg_ret = r.getrandbits(8) & 1

    def slot4(em, rr):
        em.ret(eax=lg_ret, argbytes=0)
    def slot0(em, rr):
        em.ret(eax=L, argbytes=0)
    bvt = e.fake_vtable('B_4364e0', 0x10, {0: slot0, 4: slot4})
    B = e.alloc(0x40, 4)
    e.w32(B, bvt)

    A = e.alloc(0x1360, 16)                             # the callee writes [A+0x1348]: the object must cover it
    e.wbytes(A, bytes(r.getrandbits(8) for _ in range(0x1360)))

    if r.random() < 0.2:
        s = 0
    else:
        text = bytes(r.randrange(65, 90) for _ in range(r.randrange(0, 20))) + b'\x00'
        s = e.alloc(len(text) + 16, 4)
        e.wbytes(s, text)

    flag = r.getrandbits(32) if r.random() < 0.5 else 0
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x40)))

    # logger: slot 0x20 opens a stream; stream slot 0x2c (cdecl, two arguments) records
    def rec2c(em, rr):
        em.calllog.append(('2c', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)
    svt = e.fake_vtable('stream_4364e0', 0x30, {0x2c: rec2c})
    stream = e.alloc(0x40, 4)
    e.w32(stream, svt)

    def slot20(em, rr):
        em.calllog.append(('20', em.arg32(0), em.arg32(1)))
        em.ret(eax=stream, argbytes=8)
    lvt = e.fake_vtable('logger_4364e0', 0x30, {0x20: slot20})
    logger = e.alloc(0x40, 4)
    e.w32(logger, lvt)
    e.w32(0x700390, logger)
    return [this, A, B, s, flag]


S(0x4364e0, 'constructor: vtable, fields, string copy, record count, one record, 0x437440 or logger (name GUESS; SEH frame not reproduced)',
  'thiscall', None, ret='eax', gen=_ctor, note='batch1139; SEH frame not reproduced')
