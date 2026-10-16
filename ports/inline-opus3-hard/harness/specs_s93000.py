import pe_emu
"""specs_s93000.py - hard trial opus 3: 0x4fae80, an SEH function whose EH state changes (0..3, -1 between) around four
stack objects that are registered with the engine object table (slot 0x34 of [0x70039c]+0x9b).
Every callee is a hook that (a) copies the SEH chain it sees (seh_record: next/handler/state of 3 records, so the state
written before each call is compared), (b) records its stack pointer argument RELATIVE to the current registration record
(fs:[0]; the original and the port both have the record at the same offset from their objects, so a wrong object or a wrong
offset is a mismatch, while absolute stack addresses, which differ, are not compared). The constructors write precomputed
random bytes into their object, memset really clears, and the slot 0x34 stub dumps the whole object it is given, so every
store the function makes into an object before registering it is observable. 0-2 fake outer SEH records; random /GS cookie."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _rel(emu, v):
    return (v - emu.r32(pe_emu.TEB)) & 0xffffffff   # pointer relative to the registration record at fs:[0]


def _side(c, getptr, extra=None, rows=8):
    seh = seh_record(c, depth=3)
    blk = c.emu.alloc(4 * rows, 4)

    def side(emu, k):
        seh(emu, k)
        emu.w32(blk + 4 * min(k, rows - 1), _rel(emu, getptr(emu)))
        if extra:
            extra(emu, k)
    return side


def _ctor(c, addr, n):
    data = [bytes(c.rng.getrandbits(8) for _ in range(n)) for _ in range(4)]

    def fill(emu, k):
        emu.wbytes(emu.reg('ecx'), data[min(k, 3)])
    hook_rec(c, addr, 0, this='mark', side=_side(c, lambda e: e.reg('ecx'), fill))


def _g4fae80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e.w32(0x6f5630, r.getrandbits(32))          # /GS cookie
    seh_chain(c, r.choice([0, 1, 1, 2]))

    def do_memset(emu, k):
        d, v, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.wbytes(d, bytes([v & 0xff]) * n)
    hook_rec(c, 0x634d10, 3, pop=0, stackmark=(0,), ret=lambda emu, k: emu.arg32(0),
             side=_side(c, lambda em: em.arg32(0), do_memset))
    _ctor(c, 0x469870, 0x40)
    _ctor(c, 0x4fb930, 0x98)
    _ctor(c, 0x4ccf60, 0x20)
    _ctor(c, 0x4fb9a0, 0x62)
    hook_rec(c, 0x633654, 0, this=True, side=seh_record(c, depth=2))

    sizes = [0x60, 0xb8, 0xec, 0x62]
    dump = e.alloc(sum(sizes), 4)

    def dump_obj(emu, k):
        if k < 4:
            emu.wbytes(dump + sum(sizes[:k]), emu.rbytes(emu.arg32(0), sizes[k]))
    reg = pystub(c, 1, this=True, stackmark=(0,), ret=lambda emu, k: r.getrandbits(32),
                 side=_side(c, lambda em: em.arg32(0), dump_obj))
    sysobj(c, table_slots={0x34: reg})
    return []


S(0x4fae80, 'RegisterHandlers_4fae80', 'cdecl', None, ret=None, gen=_g4fae80)
