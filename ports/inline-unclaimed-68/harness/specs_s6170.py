"""specs_s6170.py - unclaimed-68 batch 17 (claim 16): ZDistCheck::Promote (0x4a15b0). The object holds eight counters at +0x800, eight
entries at +0x804, and weights at +0x820; the helper 0x4a0e40 (area 70, original code) reads them. Values are small so the section
search finds a match most of the time; the hook at 0x7003b0 is a logging stub."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _hook(c):
    hook = c.emu.stub_fn('ZDistCheck hook', lambda em, r: (em.calllog.append(('hook', 0, 0, ())), em.ret(eax=0, argbytes=0)))
    set_global(c, 0x7003b0, hook)


def _gen(c):
    o = zero_obj(c, 0x900)
    vals = []
    flat = c.rng.random() < 0.5   # all counters and entries zero: the in-place increment chain runs to the last entry
    for i in range(8):
        vals.append(0 if flat else c.rng.randrange(0, 6))
    for i in range(8):
        c.emu.w32(o + 0x800 + 4 * i, vals[i])
    for i in range(8):
        c.emu.w32(o + 4 + 4 * i, c.rng.randrange(0, 8))
        c.emu.w32(o + 0x804 + 4 * i, 0 if flat else c.rng.randrange(0, 12))
    idx = c.rng.randrange(0, 8)
    c.steered = False
    if c.rng.random() < 0.4:
        c.steered = True
        # steer: the counter at +0x800+4k and the entry at +0x804+4k are the same memory (entry k is counter k+1). Counters 0..8 are
        # zero except counter 4 (= entry 3), which is 7. The helper then picks section 3 for idx 1..7, and the chain runs through
        # entries 4..7; entry 7 is +0x820, which is also the weight of section 0, so section 3 keeps the difference visible.
        for k in range(9):
            c.emu.w32(o + 0x800 + 4 * k, 7 if k == 4 else 0)
        idx = c.rng.randrange(1, 8)
    return [o, idx]


S(0x4a15b0, 'ZDistCheck::Promote (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_hook,
  note='unclaimed-68 batch 17; helper 0x4a0e40 (area 70) as exe code; hook stubbed')
