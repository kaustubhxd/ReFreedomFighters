"""specs_s303.py - unclaimed-43 batch 303: vector clear-then-append (0x5ac960), thiscall, two stack args, ret 8.
Object: vector at +0x6e (begin, finish +0x72, end +0x76), flag byte +0x19, objects at +0x1a and +0x42 (logging vtables with
slot 0x280 taking two stack words). The spec uses the flag-on path only (the flag-off path copies a stale frame word
into the record: a quirk, see batch303.cpp). Three vector shapes: insert (begin == end, the insert helper runs), store
(room after begin), null begin (finish += 16 with no store). arg1 == 0 is in the mix for the early return."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E

NSLOTS = 0x284 // 4


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x400)
    c.emu.wbytes(o + 0x19, bytes([1]))
    obj1 = E.logged_obj(c, 'ZVECOBJ1', NSLOTS, impl={}, argwords={0x280: 2})
    obj2 = E.logged_obj(c, 'ZVECOBJ2', NSLOTS, impl={}, argwords={0x280: 2})
    c.emu.w32(o + 0x1a, obj1)
    c.emu.w32(o + 0x42, obj2)
    buf = c.bytes_(16 * 8)
    mode = r.choice(['insert', 'store', 'store', 'nullbegin'])
    if mode == 'insert':
        begin = end = buf
        finish = buf + 16 * r.randrange(0, 3)
    elif mode == 'store':
        begin = buf
        end = buf + 16 * r.randrange(1, 5)
        finish = buf + 16 * r.randrange(0, 4)
        if r.random() < 0.15:
            finish += 4          # size not a multiple of 16: the clear leaves begin + 4
    else:
        begin = 0
        end = buf + 16
        finish = 16 * r.randrange(0, 2)
    c.emu.w32(o + 0x6e, begin)
    c.emu.w32(o + 0x72, finish)
    c.emu.w32(o + 0x76, end)
    arg1 = 0 if r.random() < 0.08 else (r.getrandbits(31) | 1) << 1
    arg2 = r.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, arg1, arg2]


def _stub_malloc(c):
    # CRT malloc (cdecl, through the import that __builtin_new 0x41e290 jumps to): a block from the fake heap.
    def h(em, rr):
        em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=0)
    c.emu.stub_import('malloc', h)


S(0x5ac960, 'vector clear-then-append (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_stub_malloc,
  note='unclaimed-43 batch 303; flag-on path; _M_insert_aux 0x5acad0 is original exe code; malloc stubbed (insert path)')
