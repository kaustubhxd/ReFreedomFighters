"""Strict fixture for the entry-descriptor rebuild routine at 0x63d2f0."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, pystub, rnd


def g63d2f0(c):
    clear_hooks(c)
    e, r = c.emu, c.rng

    # Choose descriptor 2: its table entry reaches the selected-record rewrite,
    # virtual grow/finalize calls, and the caller-cleaned eight-byte copy.
    self_ = rnd(c, 0x140)
    a0 = rnd(c, 0x80)
    a1 = 0x100
    ident = 2
    e.w16(a0 + 0x5a, ident)

    engine = rnd(c, 0x1ac0)
    registry = rnd(c, 0x40)
    key_base = r.getrandbits(28)
    e.w32(0x70039c, engine)
    e.w32(engine + 0x1aa3, registry)
    e.w32(registry + 0x20, key_base)
    key = key_base + a1

    table = rnd(c, 0x20)
    record = rnd(c, 0x50)
    # These extra records make the two table-index mutants safe and observable.
    masked_record = rnd(c, 0x50)
    shifted_record = rnd(c, 0x50)
    e.w32(self_ + 0x68, table)
    e.w32(table + ident * 4, record)
    e.w32(table, masked_record)
    e.w32(table + 16, shifted_record)
    e.w8(record + 0x3d, ident)
    e.w8(record + 0x3e, 1)
    e.w8(masked_record + 0x3d, 1)
    e.w8(shifted_record + 0x3d, 1)

    # A matching first slot avoids the optional system-list walk; a zero count
    # likewise selects the direct record-rebuild path.
    e.w32(self_ + 0xec, 0)
    old = rnd(c, 0x40)
    owned = rnd(c, 0x20)
    moved = rnd(c, 0x20)
    e.w32(old, owned)
    e.w32(old + 4, key)
    e.w32(old + 8, moved)
    e.w32(old + 12, r.getrandbits(32))
    e.w32(record + 0x40, old)

    new = rnd(c, 0x40)
    vt = rnd(c, 0x28)

    def grow_side(emu, _k):
        emu.calllog.append(('grow', emu.reg('ecx'), emu.arg32(0)))

    def done_side(emu, _k):
        emu.calllog.append(('done', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))

    e.w32(vt + 0x20, pystub(c, 1, ret=new, this=True, side=grow_side))
    e.w32(vt + 0x24, pystub(c, 2, ret=0, this=True, side=done_side))
    e.w32(self_, vt)

    def copy_side(emu, _k):
        dst, src, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('copy', dst, src, n))
        emu.wbytes(dst, emu.rbytes(src, n))

    hook_rec(c, 0x634d22, 3, ret=lambda emu, _k: emu.arg32(0),
             pop=0, this=False, side=copy_side)
    return [self_, a0, a1]


S(0x63d2f0, 'rebuild_entry_descriptor', 'thiscall', None, ret='eax',
  gen=g63d2f0, note='batch220010 hand port; selected record rebuild/copy path')
