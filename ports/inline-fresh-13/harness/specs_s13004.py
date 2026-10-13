"""specs_s13004.py - fresh-13 batch 4: 0x62fe10 zlib _tr_flush_block(s, buf, stored_len, eof), cdecl. Every callee is a
logged cdecl hook (one call log, so order and arguments are compared; build_bl_tree returns 0..18). The state is 0x1700
random bytes with: level (+0x7c) in {-1, 0, 1..9, random}; data_type byte (+0x1c) 0/1/2; opt_len / static_len (+0x16a0 /
+0x16a4) small, sometimes equal, sometimes huge (wrap); bi_valid (+0x16b4) 0..16 (sometimes random); pending_buf (+8) a
64-byte heap buffer and pending (+0x14) 0..40. stored_len is chosen around opt_lenb (both sides of the +4 test, and
0xfffffffc..ff for the wrap); buf is null in 15% of cases."""
from pilot import S
from fr13 import Log, loghook, rnd, clear_hooks, flush

HOOKS = [(0x631620, 1), (0x6302f0, 2), (0x630070, 4), (0x6304f0, 3), (0x630ec0, 4), (0x630c50, 1), (0x6301a0, 1)]


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=16)
    for i, (a, n) in enumerate(HOOKS):
        loghook(c, log, a, n, i + 1, this=False, pop=False)
    loghook(c, log, 0x630200, 1, 9, ret=r.randint(0, 18), this=False, pop=False)
    s = rnd(c, 0x1700)
    lvl = r.choice([-1, 0, 0, 1, 6, 9, r.getrandbits(32)])
    c.emu.w32(s + 0x7c, lvl & 0xffffffff)
    c.emu.w8(s + 0x1c, r.choice([0, 1, 2, 2]))
    opt = r.randint(0, 4000)
    st = opt if r.random() < 0.3 else r.randint(0, 4000)
    if r.random() < 0.05:
        opt = r.getrandbits(32)
    c.emu.w32(s + 0x16a0, opt)
    c.emu.w32(s + 0x16a4, st)
    c.emu.w32(s + 0x16b4, r.randint(0, 16) if r.random() < 0.9 else r.getrandbits(32))
    c.emu.w32(s + 8, rnd(c, 64))
    c.emu.w32(s + 0x14, r.randint(0, 40))
    lvl_pos = (lvl & 0xffffffff) < 0x80000000 and lvl != 0
    ref = (min(opt, st) + 10) >> 3 if lvl_pos else 0
    k = r.random()
    if k < 0.1:
        stored = r.randint(0xfffffff8, 0xffffffff)
    elif lvl_pos:
        stored = max(0, ref - 4 + r.randint(-3, 3))
    else:
        stored = r.randint(0, 5000)
    buf = 0 if r.random() < 0.15 else rnd(c, 16)
    flush(c)
    return [s, buf, stored & 0xffffffff, r.choice([0, 1, 1, r.getrandbits(32)])]


S(0x62fe10, 'zlib _tr_flush_block', 'cdecl', None, ret=None, gen=_gen,
  note='fresh13 batch13004; zlib 1.2.3 trees.c; eight cdecl callees logged')
