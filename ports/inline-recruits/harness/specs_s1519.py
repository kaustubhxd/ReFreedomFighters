"""specs_s1519.py - recruits thread batch 1519: LevelComplete (0x59be70), GUESS names for the group count (0x59d1b0)
and all-bits (0x59d090), and GiveRemainingCharisma (0x59b710).
The ZFFLevelController is a random object with: the level name inline at +0x48 ("C01A", "C00A" or another name);
the CSaveMissions save records at this+0x50f (built like batch 1518); the bit groups at this+0x3b1 (counts at
+0x463+4k, which is the flag +0x467 for k = 1, as in the original); the flag +0x41a.
Recorders replace the callees whose internals are not under test: CharismaAddExperience (0x596940, verified in
batch 1507), GetGameOSD (0x589c20), GetNoOfPrisonersFollowingHero (0x5acfb0). The save-missions functions and the
bit helpers run as exe code."""
from pilot import S
from recruits_util import rnd, obj, hook_rec, clear_hooks, stub_memset


def _missions(c, mb):
    r = c.rng
    e = c.emu
    prefixes = [b'C01A', b'C00A', b'C02A', b'C05A']
    n = r.randint(0, 6)
    e.w32(mb + 0x5b8, n)
    for i in range(n):
        s = r.choice(prefixes) + bytes([0x61 + i]) + b'\0'
        a = c.emu.alloc(len(s) + 4, 4)
        e.wbytes(a, s)
        e.w32(mb + 8 + 4 * i, a)
        e.w32(mb + 0x5c0 + 4 * i, r.choice([0, 0, 0, 4, 1]))
        e.w32(mb + 0x3c8 + 4 * i, r.choice([0, 1, 2]))
        e.w32(mb + 0x790 + 4 * i, r.getrandbits(32))


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    self_ = rnd(c, 0x2000)
    name = r.choice([b'C01A', b'C00A', b'C02A', b'C05A', b'C01B'])
    e.wbytes(self_ + 0x48, name + b'\0')   # the group letter is the name's last character (+0x4b)
    # the group words (+0x76..) overlap the save-record pointers (+0x517..), so the words come first, then the
    # records, then the counts (which the group's words do not reach)
    grp = self_ + 0x3b1
    for idx in range(0x40):
        e.w32(grp + 0x76 + 4 * idx, r.getrandbits(32) if r.random() < 0.6 else 0xffffffff)
    _missions(c, self_ + 0x50f)
    for k in range(5):
        e.w32(grp + 0xb2 + 4 * k, r.choice([0, r.randint(1, 8), r.randint(1, 40)]))
    e.w8(self_ + 0x41a, 0)
    osd = rnd(c, 0x2400)
    hook_rec(c, 0x596940, 4, this=True, nullflag=(1,))
    hook_rec(c, 0x589c20, 1, ret=osd, this=True)
    hook_rec(c, 0x5acfb0, 0, ret=r.randint(0, 6), this=True)
    game = rnd(c, 0x100)
    e.w32(0x7003b8, game)
    return [self_]


S(0x59be70, 'ZFFLevelController::LevelComplete', 'thiscall', ret='al', gen=_gen, note='batch1519')
S(0x59d1b0, 'ZFFLevelController group count (GUESS, 0x59d1b0)', 'thiscall', ret='eax',
  gen=lambda c: _gen(c) + [c.rng.randint(0, 4)], note='batch1519')
S(0x59d090, 'ZFFLevelController group all-set (GUESS, 0x59d090)', 'thiscall', ret='al',
  gen=lambda c: _gen(c) + [c.rng.randint(0, 4)], note='batch1519')
S(0x59b710, 'ZFFLevelController::GiveRemainingCharisma', 'thiscall', gen=_gen, note='batch1519')
