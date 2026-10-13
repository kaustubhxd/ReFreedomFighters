"""specs_s13001.py - fresh-13 batch 1: two addMethodDefinitions (0x604710, 0x50d190). Thiscall, one stack argument (the
method list, ret 4). The counts (0x724768 / 0x7012c8) are drawn from 0..60 (biased to just below 50) so the table path and
the full path both run; the flag +0xc is mostly set. Every callee is a logged hook: list add 0x5f9940 (3 args), the tail
0x5f9b80 (1 arg), this->vtbl[+0x44] (1 arg) and the hook at 0x7003b0 (no args), all in one call log, so order, count and
arguments are compared. The tables live in .data and are compared by value."""
from pilot import S
from fr13 import Log, loghook, logstub, rnd, clear_hooks, flush


def _count(r):
    k = r.random()
    return r.randint(40, 52) if k < 0.6 else r.randint(0, 60)


def _common(c, cnt_addr):
    r = c.rng
    clear_hooks(c)
    log = Log(c)
    self_ = rnd(c, 0x100)
    vt = c.emu.alloc(0x100, 4)
    c.emu.w32(vt + 0x44, logstub(c, log, 1, 3))
    c.emu.w32(self_, vt)
    lst = rnd(c, 0x40)
    c.emu.w8(lst + 0xc, r.choice([0, 1, 1, 1, 1, 0x80]))
    c.emu.w32(cnt_addr, _count(r))
    # The hook sometimes clears the list's flag (a stand-in for a hook with side effects), so the per-block flag
    # re-read is exercised.
    clr = r.random() < 0.3
    def _ret(e, lst=lst, clr=clr):
        if clr:
            e.w8(lst + 0xc, 0)
        return 0
    c.emu.w32(0x7003b0, logstub(c, log, 0, 4, this=False, ret=_ret))
    loghook(c, log, 0x5f9940, 3, 1)
    loghook(c, log, 0x5f9b80, 1, 2)
    flush(c)
    return [self_, lst]


S(0x604710, 'OpaqueString_t::addMethodDefinitions', 'thiscall', None, ret=None, gen=lambda c: _common(c, 0x724768),
  note='fresh13 batch13001; 11 methods; add 0x5f9940 / tail 0x5f9b80 / hook 0x7003b0 logged')
S(0x50d190, 'ZScriptItemInterface_t::addMethodDefinitions', 'thiscall', None, ret=None, gen=lambda c: _common(c, 0x7012c8),
  note='fresh13 batch13001; 20 natives; vtbl+0x44 and hook 0x7003b0 logged')
